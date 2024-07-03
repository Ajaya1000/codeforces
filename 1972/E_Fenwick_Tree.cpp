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
const int N = 1e6 + 100;

ll inv[N];

inline int lowbit(int x) {
    return x & (-x);
}

void pre() {

    inv[0] = inv[1] = 1;
    rep(i,2,N-1) inv[i] = (((mod - (mod/i)) % mod) * inv[mod%i]) % mod;
}


void solve()
{
    int n,k; cin>>n>>k;

    ll a[n+1];
    rep(i,1,n) cin>>a[i];

    rep(i,1,n) {
        
        ll curr = 1;

        int x = i;
        int d = 0;

        for(int x = i + lowbit(i), d = 1; x<=n; x+= lowbit(x), d++) {
            curr = (curr * (((k+d-1) * inv[d]) % mod)) % mod;
            a[x] = (mod + (a[x] - (a[i]*curr) % mod) % mod) % mod;
        }
    }

    rep(i,1,n) cout<<a[i]<<" ";
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
