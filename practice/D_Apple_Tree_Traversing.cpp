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
    int n; cin>>n;
    vector<vector<int>> mat(n);
    rep(i,1,n-1) {
        int u,v; cin>>u>>v;
        u--,v--; 

        mat[u].pb(v);
        mat[v].pb(u);
    }

    vector<array<int,3>> ans;
    vector<bool> used(n,0);
    vector<bool> visited(n,0);
    vector<int> par(n,-1);

    while(count(used.begin(), used.end(), false) != 0) {
        visited.assign(n,0);
        par.assign(n,-1);

        function<pii(int,int)> dfs = [&](int u, int p) -> pii {
            pii maxx = {1,u};
            visited[u] = 1;
            par[u] = p;

            for_each(v, mat[u]) {
                if(v==p || used[v]) continue;

                auto curr = dfs(v,u);
                curr.first++;
                maxx = max(maxx, curr);
            }

            return maxx;
        };

        rep(i,0,n-1) {
            if(!used[i] && !visited[i]) {
                auto [d1, j] = dfs(i,-1);
                auto [d2, k] = dfs(j,-1);

                ans.pb({d2, max(j,k)+1, min(j,k)+1});

                while(k!=-1) {
                    used[k] = 1;
                    k = par[k];
                }
             }
        }
    }

    sort(ans.begin(), ans.end(), greater<array<int,3>>());

    for_each(vec, ans) for_each(x, vec) cout<<x<<" ";
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
