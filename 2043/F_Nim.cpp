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

#define mod 998244353

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

void printAns(int l, int r, vector<vector<int>> &b) {
    int count[51]; memset(count,0,sizeof(count));

    rep(i,0,50) count[i] = b[r][i] - ((l > 0)? b[l-1][i]: 0);

    vector<pll> dp(65, {-1,-1});

    int prev_tot = 0;
    rep(i,0,50) {
        vector<pll> nxt(65, {-1,-1});

        // for 0 count
        rep(j,0,64) {
            pll temp0 = {-1,-1};
            if(dp[j].first != -1) temp0 = {dp[j].first + count[i], (dp[j].second*1)%mod};

            pll temp1 = {-1,-1};
            if(count[i] > 0 && dp[j^i].first != -1) temp1 = {dp[j^i].first + count[i] - 1, (dp[j^i].second * count[i]) % mod};

            pll temp2 = {-1,-1};
        }

        prev_tot += count[i];
    }
}

void solve()
{
    int n,q; cin>>n>>q;
    int a[n];
    arr_in(a);
    vector<vector<int>> b(n, vector<int>(51,0));

    rep(i,0,n) {
        if(i>0) b[i] = b[i-1];
        b[i][a[i]]++;
    }

    int l,r;

    while(q--) {
        cin>>l>>r; l--,r--;
        printAns(l,r,b);
    }
}
int main()
{
    fastio;

    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}
