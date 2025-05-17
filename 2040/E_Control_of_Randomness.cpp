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

void solve()
{
    int n,q; cin>>n>>q;
    vector<vector<int>> g(n);
    rep(i,1,n-1) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<int> parent(n,-1);
    function<void(int,int)> dfs = [&] (int p, int u) {
        parent[u] = p;
        for_each(v, g[u]) if(v!=p) dfs(u,v);
    };

    dfs(-1,0);

    while (q--)
    {
        int u,p; cin>>u>>p;
        u--;

        vector<pii> vec;
        int i=0;
        while(u != 0) {
            if(i%2) vec.push_back({u, g[u].size()});
            u = parent[u];
            i++;
        }

        sort(vec.begin(), vec.end(), [](pii &a, pii &b){
            return a.second > b.second;
        });

        ll ans = (i+1)/2;
        rep(j,0,(int)vec.size() - 1) {
            auto &[u, N] = vec[j];
            if(j < p) ans = (ans + 1) % mod;
            else ans = (ans + (2ll * N - 1ll) % mod) % mod;
        }

        cout<<ans<<endl;
    }
    
}
int main()
{
    fastio;

    test
    {
        solve();
        // cout << endl;
    }

    return 0;
}
