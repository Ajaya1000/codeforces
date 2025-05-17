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
    int type1 = -1,type2 = -1;
    vector<int> typeTrue, typeFalse;
    vector<int> type(n);

    // 0: unset - 0
    // 1: set - 0 
    // 2: set - 1
    // 3: unset - 1
    rep(i,0,n-1) {
        string s,t; cin>>s>>t;
        if(t == "true") {
            if(s == "set") { type1 = i; type[i] = 2; }
            else { type2 = i; type[i] = 3; }
        } else {
            if(s == "set") { typeTrue.pb(i); type[i] = 1; }
            else { typeFalse.pb(i); type[i] = 0;}
        }
    }

    if(type1 == -1 && (type2 != -1 || typeTrue.size() != 0)) {
        cout<<-1;
        return;
    }

    int m; cin>>m;
    vector<vector<int>> mat(n);

    for_each(v, typeTrue) {
         if(type1 != -1) mat[type1].pb(v);
         if(type2 != -1) mat[v].pb(type2);
     }

    rep(i,0,m-1) {
        int u, v; cin>>u>>v; u--; v--;
        if(type[u] == 0 && type[v] == 1 && type1 != -1) mat[u].pb(type1);
        else if (type[u] == 1 && type[v] == 0 && type2 != -1) mat[type2].pb(v);
        else mat[u].pb(v);
    }


    // for_each(v, typeFalse) {
    //     if(mat[v].size() == 0 && type1 != -1) {
    //         mat[v].pb(type1);
    //     }
    // }

    vector<bool> vStack(n,0);
    vector<bool> visited(n,0);

    vector<int> ans;

    function<bool(int)> dfs = [&] (int u) -> bool {
        if(vStack[u]) return 1;
        if(visited[u]) return 0;

        visited[u] = 1;
        vStack[u] = 1;

        for_each(v, mat[u]) {
            if(dfs(v)) return 1;
        }

        ans.pb(u);
        vStack[u] = 0;

        return 0;
    };

    rep(i,0,n-1) {
        if(type[i] == 0) continue;
        if(dfs(i)) {
            cout<<-1;
            return;
        }
    }

    rep(i,0,n-1) {
        if(type[i] != 0) continue;
        if(dfs(i)) {
            cout<<-1;
            return;
        }
    }

    reverse(ans.begin(), ans.end());

    int flag = 0;

    // 0: unset - 0
    // 1: set - 0 
    // 2: set - 1
    // 3: unset - 1
    auto nxt = [&] (int i) -> int {
        if(flag == 0 && (type[i] == 1 || type[i] == 3)) return -1;
        if(flag == 1 && (type[i] == 0 || type[i] == 2)) return -1;

        if(type[i] == 1 || type[i] == 2) return 1;
        return 0;
    };

    for_each(v, ans) {
        flag = nxt(v);
        if(flag == -1) {
            cout<<-1;
            return;
        }
    }

    for_each(v, ans)
    {
        cout<<v+1<<" ";
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
