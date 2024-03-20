// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
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

#define mod 998244353

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
    int n;
    cin >> n;
    int a[n];
    for_each(v, a)
    {
        cin >> v;
        v = v % 2;
    }

    ll dp[4][4];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        if (a[i])
        {
            dp[3][3] = (dp[3][3] + dp[3][1] + dp[2][1]) % mod;
            dp[3][1] = (dp[3][1] + dp[3][2] + dp[2][2]) % mod;

            dp[2][1] = (dp[2][1] + dp[1][0]) % mod;
            dp[2][3] = (dp[2][3] + dp[1][1]) % mod;

            dp[1][1] = (dp[1][1] + 1ll) % mod;
        }
        else
        {
            dp[3][2] = (dp[3][2] + dp[3][3] + dp[2][3]) % mod;
            dp[3][0] = (dp[3][0] + dp[3][0] + dp[2][0]) % mod;

            dp[2][0] = (dp[2][0] + dp[1][0]) % mod;
            dp[2][2] = (dp[2][2] + dp[1][1]) % mod;

            dp[1][0] = (dp[1][0] + 1) % mod;
        }
    }

    ll ans = 0;
    rep(i, 0, 3) ans = (ans + dp[3][i]) % mod;

    cout << ans;
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