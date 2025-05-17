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

struct BIT {
    int N;
    vector<int> bit;

    BIT(int n) {
        N=n+1;
        bit = vector<int>(N);
    }

    void update(int idx, int v) {
        idx++;

        while(idx < N) {
            bit[idx]+=v;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        idx++;

        int res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }

        return res;
    }
};

void solve()
{
    int n; cin>>n;
    vector<int> color(n); arr_in(color);
    vector<vector<int>> mat(n);
    rep(i,1,n-1) {
        int u,v;
        cin>>u>>v;
        u--;v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    vector<int> arr;
    vector<int> st(n),et(n);

    int curr = 0;
    
    function<void(int,int)> dfs = [&] (int u, int p) {
        arr.pb(u);
        st[u] = curr++;
        for_each(v,mat[u]) {
            if(v==p) continue;
            dfs(v,u);
        }

        et[u] = curr - 1;
    };

    dfs(0,-1);

    vector<int> ans(n);

    BIT bit(n);
    map<int,int> mp;

    for(int i=n-1;i>=0;i--) {
        int u = arr[i];
        int v = color[u];

        auto it = mp.find(v);
        if(it != mp.end()) bit.update(it->second, -1);

        mp[v] = i;
        bit.update(i, 1);

        ans[u] = bit.sum(et[u]) - bit.sum(i-1);
    }

    for_each(v, ans) cout<<v<<" ";
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
