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

void update(int i, ll v, int n, ll f[]) {
    while(i<=n) {
        f[i] += v;
        i += (i & -i);
    }
}

ll getVal(int i, ll f[]) {
    ll val = 0;
    while(i>0) {
        val= (val + f[i]) % mod;
        i -= (i & -i);
    }
    return val;
}

ll getInv(int k, int q[]) {
    ll f[k+1];
    memset(f,0,sizeof(f));

    int t[k];
    rep(i,0,k-1) {
        t[q[i]] = i; 
    }

    ll sum = 0;
    repi(i,k-1,0) {
        sum = sum + getVal(t[i] + 1, f);
        update(t[i] + 1, 1, k, f);
    }

    return sum;
}

void solve()
{
    int n,k; cin>>n>>k;

    int p[n],q[k];
    for_each(v,p) cin>>v;
    for_each(v,q) cin>>v;

    ll res = (getInv(k, q) * n) % mod;
    
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