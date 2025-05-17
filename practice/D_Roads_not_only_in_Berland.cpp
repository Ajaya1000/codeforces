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

    vector<int> parent(n);
    rep(i,0,n-1) parent[i] = i;

    function<int(int)> getParent = [&](int u) -> int {
        if(parent[u] == u) return u;
        return parent[u] = getParent(parent[u]);
    };

    vector<pii> roads;

    rep(i,1,n-1) {
        int u,v; cin>>u>>v; u--,v--;
        int up = getParent(u);
        int vp = getParent(v);
        if(up == vp) {
            roads.pb({u,v});
        } else {
            parent[vp] = up;
        }
    }

    vector<bool> flag(n,0);
    vector<int> nodes;
    rep(i,0,n-1) {
        int u = getParent(i);
        if(flag[u]) continue;
        flag[u] = 1;
        nodes.pb(u);
    }

    assert(roads.size() == nodes.size() - 1);

    cout<<roads.size()<<endl;

    rep(i,0,(int)roads.size()-1) {
        cout<<roads[i].first+1<<" "<<roads[i].second+1<<" "<<nodes[i]+1<<" "<<nodes[i+1]+1<<endl;
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
