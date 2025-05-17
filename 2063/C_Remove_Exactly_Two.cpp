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
        u--;v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }
    int maxx = 0;

    function<int(int,int)> dfs = [&](int u, int p) -> int {
        int maxx_a1,maxx_a2,maxx_b;
        maxx_a1=maxx_a2=maxx_b = 0;
        for_each(v, mat[u]) {
            if(v==p) continue;
            int curr = dfs(v,u);
            maxx_b = max(maxx_b, curr);
            
            // with the parent
            curr = max(curr, (int)mat[v].size());
            // cout<<"curr "<<curr<<endl;
            if(curr >= maxx_a1) {
                maxx_a2 = maxx_a1;
                maxx_a1 = curr;
            } else if(curr > maxx_a2) {
                maxx_a2 = curr;
            }
        }

        maxx = max(maxx, maxx_a1 + maxx_a2 - 1);
        maxx = max(maxx, (int) mat[u].size() + maxx_b - 1);
        maxx = max(maxx, (int) mat[u].size() + maxx_a1 - 2);

        // cout<<"for "<<u<<" "<<maxx_a1<<" "<<maxx_a2<<" "<<maxx_b<<endl;

        return maxx_a1;
    };

    dfs(0,-1);

    cout<<maxx;
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
