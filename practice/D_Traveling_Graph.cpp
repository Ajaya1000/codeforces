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
#define B 16
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
const int N = 1<<15+5;

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> degree(n,0);

    vector<vector<ll>> mat(n,vector<ll>(n,LLONG_MAX));
    vector<vector<int>> g(n);

    rep(i,0,n-1) mat[i][i] = 0;

    ll tot = 0;
    rep(i,0,m-1) {
        int u,v;
        ll w;

        cin>>u>>v>>w;
        u--,v--;
        degree[u]++;
        degree[v]++;

        mat[u][v] = min(mat[u][v],w);
        mat[v][u] = min(mat[v][u],w);

        g[u].pb(v);
        g[v].pb(u);

        tot += w;
    }

    rep(k,0,n-1) {
        rep(i,0,n-1) {
            rep(j,0,n-1) {
                if(mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX && mat[i][j] > mat[i][k] + mat[k][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }

    vector<bool> visited(n,false);

    function<void(int)> dfs = [&](int u) {
        if(visited[u]) return;
        visited[u] = 1;

        for_each(v, g[u]) {
            dfs(v);
        }
    };

    dfs(0);

    rep(i,0,n-1) {
        if(degree[i] && !visited[i]) {
            cout<<-1;
            return;
        }
    }

   vector<ll> dp(N, LLONG_MAX);

   function<ll(int)> getDP = [&] (int x) -> ll {
        if(x == 0) return 0;
        if(dp[x] != LLONG_MAX) return dp[x];

        bitset<B> b(x);
        int i=0;
        while(b[i]==0) i++;
        b[i] = 0;
        
        ll minn = LLONG_MAX;

        rep(j,i+1,B-1) {
            if(b[j] == 0) continue;

            b[j] = 0;
            minn = min(minn, mat[i][j] + getDP(b.to_ulong()));
            b[j] = 1;
        }

        return dp[x] = minn;
   };

    int x = 0;
    repi(i,n-1,0) {
        // cout<<degree[i]<<" ";
        x = (x<<1) + (degree[i] % 2);
    }
    // cout<<endl<<x<<" ";
    cout<< tot + getDP(x);
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
