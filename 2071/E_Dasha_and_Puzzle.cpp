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
const int N = 40;

ll pw2[N];

void pre() {
    pw2[0] = 1;
    rep(i,1,N-1) {
        pw2[i] = pw2[i-1] * 2ll;
    }
}

// direction
struct Direction
{
    int dx, dy;

    Direction(int dx, int dy) {
        this->dx = dx;
        this->dy = dy;
    }

    Direction next() {
        if(dx==1 && dy==0) return Direction(0,1);
        if(dx==0 && dy==1) return Direction(-1,0);
        if(dx==-1 && dy==0) return Direction(0,-1);
        return Direction(1,0);
    }

    Direction neg() {
        return Direction(-dx, -dy);
    }
};
void solve()
{
    int n; cin>>n;
    vector<vector<int>> mat(n);
    rep(i,1,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    rep(i,0,n-1) {
        // if it has more than 4 then slution don't exist
        if(mat[i].size() > 4) {
            cout<<"NO";
            return;
        }
    }

    cout<<"YES\n";

    // subtree size;
    vector<int> size(n);

    function<int(int,int)> dfs1 = [&] (int u, int p) -> int {
        int tot = 1;
        for_each(v, mat[u]) {
            if(v==p) continue;
            tot += dfs1(v,u);
        }

        return size[u] = tot;
    };
    // calculates all the sub tree sizes
    dfs1(0,-1);

    vector<pair<ll,ll>> ans(n);

    // curr dir represent from which direction we should start
    function<void(int,int,Direction)> dfs = [&] (int u, int p, Direction curr) {
        
        for_each(v, mat[u]) {
            if(v == p) continue;
            // calculates the position of v
            int k = size[v];

            ans[v] = {ans[u].first + pw2[k] * (ll) curr.dx, ans[u].second + pw2[k] * (ll) curr.dy };
            
            // if u is parent and v is child in left direction
            // then from v, u is in right
            // so performing neg then getting the next in anti clockwise dir
            dfs(v,u, curr.neg().next());

            // chaning the curr to next for the next children
            curr = curr.next();
        }
    };

    dfs(0,-1, Direction(1,0));

    for_each(p,ans) cout<<p.first<<" "<<p.second<<endl;
}
int main()
{
    fastio;

    pre();
    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}
