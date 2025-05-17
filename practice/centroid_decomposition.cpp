// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio				   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);				  \
    cout.tie(0)
#define test  \
    int t;   \
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
int getCentTree(vector<bool> &marked, int u, vector<int> &sz, vector<vector<int>> &mat, vector<int> &parent) {
    int tot = sz[u];

    int nxt = -1;
    int sum = 1;
    for_each(v, mat[u]) {
        if(marked[v]) continue;

        if(sz[v] > (tot/2)) nxt = v;
        else sum+=sz[v];
    }

    if(nxt !=-1) {
       sz[u] = sum;
       sz[nxt] += sum;
       return getCentTree(marked,nxt,sz,mat,parent);
    }
    
    marked[u] = 1;
    for_each(v, mat[u]) {
        if(marked[v]) continue;
        int v1 = getCentTree(marked,v,sz,mat,parent);
        parent[v1] = u;
    }

    return u;
}

int dfs(int p, int u, vector<vector<int>> &mat, vector<int> &sz) {
    int sum = 1;
    for_each(v, mat[u]) {
        if(v==p) continue;
        sum += dfs(u,v,mat,sz);
    }

    return sz[u] = sum;
}

void solve()
{
    int n; cin>>n;
    vector<vector<int>> mat(n);
    rep(i,1,n-1) {
        int p;
        cin>>p; p--;
        assert(p>=0 && p<n);
        mat[i].pb(p);
        mat[p].pb(i);
    }

    vector<int> parent(n,-1);
    vector<int> sz(n,0);

    dfs(-1,0,mat,sz);

    vector<bool> marked(n,0);
    getCentTree(marked,0,sz,mat,parent);

    for_each(v, parent) cout<<v+1<<" ";
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