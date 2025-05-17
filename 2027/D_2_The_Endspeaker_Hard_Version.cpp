// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define test int t; cin >> t; while (t--)
#define pb push_back
#define endl '\n'
#define rep(i, x, y) for (auto i = x; i <= y; i++)
#define repi(i, x, y) for (auto i = x; i >= y; i--)
#define for_each(v, a) for (auto &v : a)
#define arr_in(a) for_each(v, a) cin >> v
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ff first
#define ss second
#define u_map unordered_map
#define u_set unordered_set

// define the size of the set bit
#define B 40
//

#define mod 1000000007

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
// using namespace boost::multiprecision;

template <typename T>
inline T modv(T v, T m) { return ((v % m) + m) % m; }

ll _pow(ll n, ll m)
{
    ll res = _pow(n, m / 2);

    res = res * res;
    if (m % 2)
        res = res * n;
    return res;
}

ull _powMod(ull n, ull m)
{
    if (m == 0)
        return 1;

    ull res = _powMod(n, m / 2);

    res = (res * res) % mod;
    if (m % 2)
        res = (res * n) % mod;
    return res;
}

/*
    workplace start from here
*/

void solve()
{
    int n,m; cin>>n>>m;

    ll a[n]; arr_in(a);
    ll b[m]; arr_in(b);

    rep(i,1,n-1) a[i] += a[i-1];

    vector<vector<pll>> dp(m, vector<pll>(n));
    
    auto getDP = [&] (int i, int j) -> pll {
        if(i>=m) return {LLONG_MAX, 0};
        if(j>=n) return {0,1};

        return dp[i][j];
    };

    repi(i,m-1,0) {
        map<ll, pll> mp;
        mp[0] = {1,1};
        // cout<<"for "<<i<<endl;
        int k = n-1;
        repi(j,n-1,0) {
            ll curr = b[i] + (j>0?a[j-1]:0);
            
            while(k>=j && a[k]>curr) {
                auto p = getDP(i,k+1);
                auto &[x, y] = mp[p.first];

                x = (mod + (x - p.second)) % mod;
                y--;
                if(y == 0) mp.erase(p.first);

                k--;
            }

            // cout<<"("<<k<<" "<<mp.size()<<"), ";

            ll currMinn,currCount;
            if(mp.size() && mp.begin()->first != LLONG_MAX) {
                currMinn = (mp.begin()->first+(m-i-1)) % mod;
                currCount = mp.begin()->second.first;
            } else {
                currMinn = LLONG_MAX;
                currCount = 0;
            }
            
            if(i+1<m) {
                if(dp[i+1][j].first < currMinn) {
                    currMinn = dp[i+1][j].first;
                    currCount = dp[i+1][j].second;
                } else if(dp[i+1][j].first == currMinn) {
                    currCount = (currCount +  dp[i+1][j].second)%mod;
                }
            }

            dp[i][j] = {currMinn, currCount};

            if(currMinn != LLONG_MAX) {
                auto &[x1,y1] = mp[currMinn];
                x1 = (x1 + currCount)%mod;
                y1++;
            }
        }
        // cout<<endl;
    }

    auto ans = dp[0][0];
    if(ans.first == LLONG_MAX) cout<<-1;
    else cout<<ans.first<<" "<<ans.second;

    // rep(i,0,m-1) {
    //     rep(j,0,n-1) cout<<dp[i][j].first<<" "<<dp[i][j].second<<"   ";
    //     cout<<endl;
    // }
}
int main()
{
    fastio;

    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
