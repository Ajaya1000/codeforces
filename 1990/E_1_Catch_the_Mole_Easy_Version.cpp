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
const int N = 71;

void solve()
{
    int n;cin>>n;
    vector<vector<int>> mat(n+1);
    vector<int> parent(n+1);
    vector<int> d(n+1);

    mat[1].pb(0);
    rep(i,1,n-1) {
        int u,v;cin>>u>>v;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    function<void(int,int)> dfs = [&](int p, int u) {
        parent[u] = p;
        d[u] = 1;
        for_each(v, mat[u]) {
            if(v==p) continue;
            dfs(u,v);
            d[u] = max(d[u], 1+d[v]);
        }
    };

    dfs(0,1);

    int query = 0;

    int type[3];
    memset(type,0,sizeof(type));

    auto queryUpdated = [&query, &type](int y) {
        query++;
        if(query > 162) exit(6+y+1000*type[y]);
    };

    function<int(int)> getAnyLeaf = [&] (int u) -> int {
        if(mat[u].size() == 1) return u;
        if(mat[u][0] == parent[u]) return getAnyLeaf(mat[u][1]);
        return getAnyLeaf(mat[u][0]);
    };

    auto outQuery = [&](int v, int y) {
        cout<<"? "<<v<<endl;cout.flush();queryUpdated(y);
        type[y]++;
    };

    auto outAns = [&](int v) {
        cout<<"! "<<v<<endl;cout.flush();
    };

    int r;
    int leaf = getAnyLeaf(1);

    rep(x,1,N) {
        outQuery(leaf,1);
        cin>>r;
        if(r) {
            outAns(leaf);
            return;
        }
    }

    int root = 1;
    while(1) {
        if(d[root] == -1) exit(5);
        d[root] = -1;
        vector<int> valid;
        for_each(v, mat[root]) {
            if(v == root || d[v]<=N) continue;
            valid.pb(v);
        }

        if(valid.size() == 1) {
            root = valid[0];
            continue;
        }

        bool flag = false;
        
        for_each(v, valid) {
            outQuery(v,0);
            cin>>r;
            if(r){
                root = v;
                flag = 1;
                break;
            }
        }

        if(flag) continue;

        vector<int> all;
        int curr = root;
        while(curr != 0) {
            all.pb(curr);
            curr = parent[curr];
        }

        reverse(all.begin(),all.end());
        
        int lu = 0;
        int ru = all.size()-1;
        while(lu < ru-1) {
            int mid = lu + (ru-lu)/2;
            outQuery(all[mid],2);
            cin>>r;
            if(r) {
                lu=mid;
            } else {
                lu = max(lu-1,0);
                ru = mid-1;
            }
        }
        
        outQuery(all[ru],2);
        cin>>r;
        if(r) outAns(all[ru]);
        else outAns(max(1,parent[all[lu]]));
        return;
    }   

    outAns(-2);
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
