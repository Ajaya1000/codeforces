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
    if (m == 0)
        return 1;
        
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
const int N = 1e18+100;
vector<ll> vec;

void pre() {
    ll x = 1;
    while(vec.size()<=30) {
        vec.push_back(x);
        x = x * 4ll + 1ll;
    }
    cout<<endl;
}

ll getVal(ll m, int k) {
    int n = vec.size();

    vector<vector<vector<ll>>> dp(k+1, vector<vector<ll>>(2,vector<ll>(2,0)));
    dp[0][1][0] = 1;

    // cout<<endl<<"for "<<m<<endl;
    repi(i,n-1,0) {
        int v = m / vec[i];
        m = m % vec[i];
        // cout<<v<<" ";
        vector<vector<vector<ll>>> nxt(k+1, vector<vector<ll>>(2,vector<ll>(2,0)));
        rep(s,0,k) {
            rep(j,0,3) {
                if(s+j > k) break;

                if(v==j) {
                    nxt[s+j][1][0] += dp[s][1][0];
                    nxt[s+j][0][0] += dp[s][0][0];

                    if(j == 0) {
                        nxt[s+j][1][1] += dp[s][1][1];
                        nxt[s+j][0][1] += dp[s][0][1];
                    }
                } else if(j < v) {
                    nxt[s+j][0][0] += dp[s][1][0];
                    nxt[s+j][0][0] += dp[s][0][0];

                    if(j == 0) {
                       nxt[s+j][0][1] += dp[s][1][1];
                       nxt[s+j][0][1] += dp[s][0][1];
                    }
                } else {
                    nxt[s+j][0][0] += dp[s][0][0];
                }
            }

            if(s+4 <= k) {
                dp[s+4][0][1] += dp[s][0][0];
                if(v==4) {
                    dp[s+4][1][1] += dp[s][1][0];
                }
            }
        }

        dp = nxt;
    }
    // cout<<endl;
    return dp[k][0][0] + dp[k][0][1] + dp[k][1][0] + dp[k][1][1];
}

ll solve()
{
    ll l,r,k; cin>>l>>r>>k;
    if(k >= 90) return 0;

    l--;

    return getVal(r,k) - getVal(l,k);
}
int main()
{
    fastio;

    pre();
    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}
