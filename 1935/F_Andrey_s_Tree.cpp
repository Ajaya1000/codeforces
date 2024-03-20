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

bool isValid(int u, int v, int n) {
    if(u>=0 && v<n) return 1;
    return 0;
}

void pre(int &timer,int p, int u, vector<vector<int>> &mat,vector<pii> &dp,vector<int> &dp_in,vector<int> &dp_out) {
    dp_in[u] = timer++;

    dp[u].ff = u;
    dp[u].ss = u;

    for_each(v,mat[u]) {
        if(v==p) continue;
        pre(timer,u,v,mat,dp,dp_in,dp_out);
        dp[u].ff = min(dp[u].ff, dp[v].ff);
        dp[u].ss = max(dp[u].ss, dp[v].ss);
    }
    dp_out[u] = timer - 1;
}

bool isAncestor(int u,int v,vector<int> &dp_in,vector<int> &dp_out) {
    return (dp_in[u]<dp_in[v] && dp_out[u]>=dp_out[v]);
}

void giveAns(int p, int u, int minn, int maxx, vector<vector<int>> &mat,vector<pii> &dp,vector<vector<pii>> &ans,vector<int> &dp_in,vector<int> &dp_out) {

    for_each(v,mat[u]) {
        if(v==p) continue;
        int mn = dp[v].ff;
        int mx = dp[v].ss;

        if(mn - 1 >=0 && mn-1 != u) {
            for_each(v1,mat[u]) {
                if(v1 == p || v1 == v) continue;
                if(isAncestor(v1,mn-1,dp_in,dp_out)) {
                    
                }
            }
        }
    }
}

void solve()
{
    int n;cin>>n;
    int u,v;
    vector<vector<int>> mat(n);
    vector<pii> dp(n);
    vector<int> dp_in(n);
    vector<int> dp_out(n);

    vector<vector<pii>> ans(n);

    rep(i,0,n-2) {
        cin>>u>>v;
        u--,v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }
    int timer = 0;
    pre(timer,-1,0,mat,dp,dp_in,dp_out);

    giveAns(-1,0,n,-1,mat,dp,ans,dp_in,dp_out);
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