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

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
// using namespace boost::multiprecision;

template <typename T>
inline T modv(T v, T m) { return ((v % m) + m) % m; }
const ll mod = 998244353;

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
const int N = 4e5 + 5;
ll inv[N];
ll fact[N];
ll inv_fact[N];

void pre() {

    inv[0] = inv[1] = 1;
    rep(i,2,N-1) inv[i] = ((mod - (mod/i)) * inv[mod%i]) % mod;
    
    fact[0] = fact[1] = 1;
    rep(i,2,N-1) fact[i] = (fact[i-1]*i) % mod;

    inv_fact[N-1] = _powMod(fact[N-1], mod-2) % mod;
    repi(i,N-2,0) inv_fact[i] = (inv_fact[i+1] * (ll)(i+1)) % mod;
}

ll C(int n, int k) {
    return (fact[n] * ((inv_fact[k] * inv_fact[n-k]) % mod)) % mod;
}

ll Cat(int n) {
    return (C(2*n, n) * inv[n+1]) % mod;
}

inline ll f(int n) {
    if(n==1 || n==0) return 1;
    return Cat(n-1);
}

void solve()
{
    int n,m; cin>>n>>m;
    vector<pii> vec;

    rep(i,0,m-1) {
        int l,r; cin>>l>>r;
        vec.pb({l,r});
    }

    rep(i,1,n)  vec.pb({i,i});
    vec.pb({1,n});

    m = vec.size();

    sort(vec.begin(), vec.end(), [&](pii &a, pii &b){
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    });

    vector<int> parent(m,-1);

    stack<int> s;
    s.push(0);

    auto doInterset = [&](int i, int j) -> bool {
        auto &[l1,r1] = vec[i];
        auto &[l2,r2] = vec[j];

        return max(l1,l2) <= min(r1,r2);
    };

    rep(i,1,m - 1) {
        while(s.size() && !doInterset(s.top(),i)) s.pop();
        parent[i] = s.top();
        s.push(i);
    }
    // make tree out of parent
    vector<vector<int>> mat(m);

    rep(i,1,m-1) mat[parent[i]].pb(i);
    
    ll curr = 1;
    function<void(int)> dfs = [&] (int u) {
        ll count = mat[u].size();

        curr = (curr * f(count)) % mod;

        for_each(v, mat[u]) dfs(v);
    };

    dfs(0);

    cout<<curr;
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
