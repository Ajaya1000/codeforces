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

u_set<int> dfs(int p, int u, vector<int> mat[], vector<int> vec[], int &t) {
    vector<u_set<int>> temp;
    u_set<int> f;

    for_each(v,mat[u]) {
        if(v == p) continue;
        auto s = dfs(u,v,mat,vec,t);
        if(s.empty()) continue;
        temp.pb(s);
        f.insert(s.begin(), s.end());
    }

    if(temp.size() < 2) {
        return f;
    }

    for_each(s, temp) {
        for_each(v,s) {
            
        }
    }
}

void solve()
{
    int n;cin>>n;
    vector<int> mat[n];
    int u,v;
    rep(i,1,n-1) {
        cin>>u>>v;
        u--,v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    int k;cin>>k;
    u_map<int,u_map<int, int>> m;
    vector<int> vec[k];

    rep(i,0,k-1) {
        cin>>u>>v;
        u--,v--;
        m[u][v] = i;
        m[v][u] = i;
    }

    int t = 0;
    dfs(-1,0,mat,vec,t);
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