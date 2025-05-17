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

void solve()
{
    int n,m,q; cin>>n>>m>>q;

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<vector<pii>>> ans(n, vector<vector<pii>>(n));

    rep(i,0,n-1) dp[i][i] = 0;

    vector<vector<int>> edges;
    rep(i,0,m-1) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edges.pb({u,v,w});
        dp[u][v] = 1;
        dp[v][u] = 1;
    }

    sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) { return a[2]>b[2]; });

    auto add = [](int i1, int i2) {
        if(i1 == INT_MAX || i2 == INT_MAX) return INT_MAX;

        return i1+i2;
    };

    rep(k,0,n-1) {
        rep(i,0,n-1) {
            rep(j,0,n-1) {
                dp[i][j] = dp[i][j] = min(dp[i][j], add(dp[i][k], dp[k][j]));
            }
        }
    }

    vector<int> parent(n);
    vector<int> rank(n,0);

    rep(i,0,n-1) parent[i] = i;

    function<int(int)> findParent = [&parent, &findParent] (int u) -> int {
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    };

    repi(k,m-1,0) {
        int u=edges[k][0];
        int v=edges[k][1];

        int up = findParent(u);
        int vp = findParent(v);

        if(up == vp) continue;
        
        if(rank[up] > rank[vp]) {
            parent[vp] = up;
        } else if(rank[up] < rank[vp])  {
            parent[up] = vp;
        } else {
            parent[vp] = up;
            rank[up]++;
        }
        
        rep(i,0,n-1) {
            rep(j,0,n-1) {
                int ip = findParent(i);
                int jp = findParent(j);

                if(ip==jp) dp[i][j] = 0;
                else {
                    int minn = min(add(dp[ip][up], dp[vp][jp]), add(dp[ip][vp], dp[up][jp]));
                    dp[ip][jp] = min(dp[ip][jp], minn);
                    dp[i][j] = min(dp[i][j], dp[ip][jp]);
                }

                if(ans[i][j].empty() || ans[i][j].back().first > dp[i][j]) {
                    ans[i][j].push_back({dp[i][j], k});
                }
            }
        }
    }

    rep(i,0,n-1) rep(j,0,n-1) reverse(ans[i][j].begin(),ans[i][j].end());

    while(q--) {
        int u, v, k; cin>>u>>v>>k; u--,v--;
        auto it = lower_bound(ans[u][v].begin(), ans[u][v].end(), make_pair(k, -1)); it--;
        int i = it->second;
        cout<<edges[i][2]<<" ";
    }   
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
 
 /*
 4 2 2 1 
0 0 1 1 
0 0 0 1 

4 2 2 1 
(0 1), (1 2), (2 3), 
(0 2), (1 3), 

 */