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
u_map<ull,pair<ull,ull>> dp;

ull giveAns(ull v,ull n) {
return (dp[n].first + ((v-1ll) * dp[n].second) % mod) % mod;
}

ull getVal(ull v, ull n) {
    if(dp.count(n)) {
        return giveAns(v,n);
    }

    ull m = (1+n)/2;

    ull l = getVal(2, m);
    ull r = getVal(3, n-m);

    ull k1 = ((_powMod(2, m) + mod - 1ll ) * (_powMod(2, n-m) + mod - 1ll)) % mod;

    auto p1 = dp[m];
    auto p2 = dp[n-m];

    dp[n] = {(l + r + k1)%mod, (p1.second * 2ll + p2.second * 2ll + k1)%mod};

    return giveAns(v,n);;
}

void solve()
{
    ll n;cin>>n;

    cout<<getVal(1,n);
}
int main()
{
    fastio;
    dp[1] = {1,1};

    test
    {
        solve();
        cout << endl;
    }

    return 0;
}