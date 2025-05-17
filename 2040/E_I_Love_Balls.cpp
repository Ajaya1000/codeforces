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
#define pll pair<ll, ll>
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

struct ModNum {
    ll x;

    ModNum() {
        x = 0;
    }

    ModNum(ll x) {
        this->x = x;
    }

    ModNum operator+(const ModNum &b) {
        ll y = (x + b.x) % mod;
        return ModNum(y);
    }

    ModNum operator-(const ModNum &b) {
        ll y = (x - b.x) % mod;
        y = (y + (ll) mod) % mod;
        return ModNum(y);
    }

    ModNum operator*(const ModNum &b) {
        ll y = (x * b.x) % mod;
        return ModNum(y);
    }

    ModNum operator/(const ModNum &b) {
        ll inv = _powMod(b.x, mod - 2);

        ll y = (x * inv) % mod;
        return ModNum(y);
    }

    // with ll
    ModNum operator+(ll b) {
        ll y = (x + b) % mod;
        return ModNum(y);
    }

    ModNum operator-(ll b) {
        ll y = (x - b) % mod;
        y = (y + (ll) mod) % mod;
        return ModNum(y);
    }

    ModNum operator*(ll b) {
        ll y = (x * b) % mod;
        return ModNum(y);
    }

    ModNum operator/(ll b) {
        ll inv = _powMod(b, mod - 2);

        ll y = (x * inv) % mod;
        return ModNum(y);
    }
};

/*
    workplace start from here
*/

ModNum expVal(ModNum x, ModNum n, ModNum sum) {
    return (x*(sum/n));
}

pair<ModNum,ModNum> getValue(ll n, ModNum sum) {
    ll x = (n+1ll) / 2ll;
    ll y = n - x;

    auto ans1 = expVal(x,n,sum);
    auto ans2 = expVal(y,n,sum);

    return make_pair(ans1, ans2);
}

void solve()
{
    ll n,k; cin>>n>>k;

    ll a[n]; arr_in(a);

    ModNum sum = ModNum();

    rep(i,0,k-1) {
        sum = sum + a[i];
    }

    auto ans1 = getValue(n-k+1, sum);

    sum = 0;
    rep(i,k,n-1) {
        sum = sum + a[i];
    }

    auto ans2 = getValue(n-k, sum);

    auto res1 = ans1.ff + ans2.ff;
    auto res2 = ans1.ss + ans2.ss;

    cout<<res1.x<<" "<<res2.x;
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
