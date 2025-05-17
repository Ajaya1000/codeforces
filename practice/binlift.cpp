// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                    \
    \ 
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

void binlift(int n, vector<vector<int>> &mat, vector<pii> &queries)
{
    const int N = log2(n);

    vector<int> lev(n);

    vector<vector<int>> dp(n, vector<int>(N+1));

    function<void(int, int, int)> dfs = [&](int p, int u, int d)
    {
        lev[u] = d;
        dp[u][0] = p;

        for_each(v, mat[u])
        {
            if (v == p)
                continue;
            dfs(u, v, d + 1);
        }
    };

    rep(j, 1, N)
    {
        rep(i, 0, n - 1)
        {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    auto getAnc = [&] (int u, int d) -> int {
        if(d==0) return u;

        repi(i,(int)log2(d), 0) {
            if(d && (1<<i)) u = dp[u][i];
        }

        return u;
    };

    auto getLCA = [&](int u, int v) {
        if(lev[u] > lev[v]) swap(u,v);
        
        v = getAnc(v, lev[v] - lev[u]);

        repi(i,N,0) {
            if(dp[u][i] != dp[v][i]) {
                u = dp[u][i];
                v = dp[v][i];
            }
        }

        return dp[u][0];
    };

    for_each(p, queries) {
        cout<< getLCA(p.ff, p.ss);
    }
}

void solve()
{
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