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

struct ModNum {
    ll x;

    ModNum() {
        x = 0;
    }

    ModNum(ll x) {
        this->x = x;
    }

    ModNum inv() const {
        ll x_ = _powMod(x, mod - 2);

        return ModNum(x_);
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
        return b.inv() * x;
    }

    ModNum& operator+=(const ModNum &b) {
        x = (x + b.x) % mod;
        return *this;
    }

    ModNum& operator-=(const ModNum &b) {
        x = (x - b.x) % mod;
        x = (x + (ll) mod) % mod;
        return *this;
    }

    ModNum& operator*=(const ModNum &b) {
        x = (x * b.x) % mod;
        return *this;
    }

    ModNum& operator/=(const ModNum &b) {
        ll inv = _powMod(b.x, mod - 2);
        x = (x * inv) % mod;
        return *this;
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

    ModNum& operator+=(ll b) {
        x = (x + b) % mod;
        return *this;
    }

    ModNum& operator-=(ll b) {
        x = (x - b) % mod;
        x = (x + (ll) mod) % mod;
        return *this;
    }

    ModNum& operator*=(ll b) {
        x = (x * b) % mod;
        return *this;
    }

    ModNum& operator/=(ll b) {
        ll inv = _powMod(b, mod - 2);

        x = (x * inv) % mod;
        return *this;
    }
};

ostream & operator << (ostream &out, const ModNum &c) {
    out << c.x;
    return out;
}

istream & operator >> (istream &in,  ModNum &c) {
    in >> c.x;
    return in;
}

/*
    workplace start from here
*/


void solve()
{
    ModNum n,m,k; cin>>n>>m>>k;

    ModNum s = 0;

    rep(i,0,m.x-1) {
        ModNum a,b,f; cin>>a>>b>>f;
        s += f;
    }

    auto tot_n = (n * (n - 1ll)) / 2ll;
    auto tot_k = (k * (k - 1ll)) / 2ll;

    ModNum ans1 = (s*k) / tot_n;
    ModNum ans2 = (tot_k * m) / (tot_n * tot_n);

    ans1 += ans2;
    cout<<ans1;
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
