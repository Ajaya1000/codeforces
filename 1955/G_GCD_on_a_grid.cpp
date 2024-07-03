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
    int n, m;
    cin >> n >> m;

    vector<vector<ull>> a(n, vector<ull>(m));

    for_each(vec, a) for_each(v, vec)
    {
        cin >> v;
    }

    vector<vector<bool>> dp(n, vector<bool>(m));

    auto getStatus = [&](ull v) -> bool
    {
        rep(i, 0, n - 1)
        {
            rep(j, 0, m - 1)
            {
                dp[i][j] = (i == 0 && j == 0); // special case for 0,0

                if(i-1 >= 0) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }

                if(j-1 >= 0) {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }

                dp[i][j] = dp[i][j] && (a[i][j] % v == 0);
            }
        }

        return dp[n-1][m-1];
    };

    ull maxx = 1;
    rep(v, (ull)1, sqrt(a[0][0]))
    {
        if(getStatus(v)) maxx = max(maxx,v);
        if(getStatus(a[0][0]/v)) maxx = max(maxx,a[0][0]/v);
    }

    cout<<maxx;
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
