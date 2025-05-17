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
    vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(m, INT_MAX)));

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

    repi(k,m-1,0) {
        int u=edges[k][0];
        int v=edges[k][1];

        rep(i,0,n-1) {
            rep(j,0,n-1) {
                int minn = min(add(dp[i][u], dp[v][j]), add(dp[i][v], dp[u][j]));
                dp[i][j] = min(dp[i][j], minn);

                ans[i][j][k] = dp[i][j];
            }
        }
    }

    // for_each(vec, edges) cout<<vec[2]<<" ";
    // cout<<endl;

    while(q--) {
        int u, v, k; cin>>u>>v>>k; u--,v--;
        // for_each(val, ans[u][v]) cout<<val<<" "; cout<<endl;
        auto it = lower_bound(ans[u][v].begin(), ans[u][v].end(), k); it--; // < k
        int i = it - ans[u][v].begin();
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
