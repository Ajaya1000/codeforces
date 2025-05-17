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
const int N = 5e5;

ll fact[N+1];
ll inv_fact[N+1];

void pre() {
    fact[0] = 1;
    rep(i,1,N) fact[i] = (fact[i-1] * i)  % mod;
    inv_fact[N] = _powMod(fact[N], mod-2);
    repi(i,N-1,0) inv_fact[i] = (inv_fact[i+1] * (ll)(i+1)) % mod;
}

int divup(int a, int b) {
    return (a+b-1) / b;
}

void solve()
{
    int c[26]; arr_in(c);
    int s = 0;
    for_each(v,c) s+=v;

    int odd = divup(s,2);

    ll dp[odd+1]; memset(dp,0,sizeof(dp));
    dp[0] = 1;

    for_each(v,c) {
        if(v==0) continue;
        repi(i,odd,v) {
            dp[i] = (dp[i] +  dp[i-v]) % mod;
        }
    }

    ll val = ((fact[odd]* fact[s-odd]) % mod) * dp[odd];
    val = val % mod;

    for_each(v,c) val = (val * inv_fact[v]) % mod;
    val = (mod + val) % mod;
    cout<<val;
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
