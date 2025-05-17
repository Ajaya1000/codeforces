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

#define mod 998244353

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
const int N = 2e5+5;
ll inv[N];

void pre() {
    inv[0] = inv[1] = 1;
    rep(i,2,N-1) {
         inv[i] = ((mod - (mod/i)) * inv[mod%i]) % mod;
    }
}

void solve()
{
    int n; cin>>n;
    vector<vector<int>> mat(n);
    int u,v;

    rep(_,1,n-1) {
        cin>>u>>v;
        u--,v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    vector<ll> d(n);

    function<ll(int,int)> depth = [&](int p, int u) -> ll {
        ll minn = LLONG_MAX;

        for_each(v, mat[u]) {
            if(p==v) continue;
            minn = min(minn, depth(u,v));
        }

        if(minn == LLONG_MAX)  d[u] = 0;
        else d[u] = minn;

        return d[u]+1;
    };

    depth(-1,0);

    // for_each(v,d) cout<<v<<" ";cout<<endl;

    vector<ll> ans(n);
    ans[0] = 1;

    function<void(int,int)> prob = [&](int p, int u) {
         for_each(v, mat[u]) {
            if(p==v) continue;
            ll temp = (d[v]*inv[d[v]+1])%mod;
            ans[v] = (temp*ans[u])%mod;
            prob(u,v);
        }
    };

    prob(-1, 0);

    for_each(v,ans) cout<<v<<" ";
}
int main()
{
    fastio;

    pre();
    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
