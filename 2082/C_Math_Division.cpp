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

ModNum inv_p2;
void pre() {
    inv_p2 = _powMod(2, mod-2);
}

int divup(int a, int b) {
    return (a+b-1) / b;
}

void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    vector<vector<ModNum>> dp(2, vector<ModNum>(2));

    dp[0][0] = 0;
    dp[0][1] = 1;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=1;i<n;i++) {
        vector<vector<ModNum>> curr(2, vector<ModNum>(2));

        for(int j=0;j<2;j++) {
            int k = j + (s[i] - '0');
            auto e1 = dp[k/2];
            auto e2 = dp[divup(k,2)];

            curr[j][0] = inv_p2 * (e1[0]+e1[1] + e2[0]+e2[1]);
            curr[j][1] = inv_p2 * (e1[1] + e2[1]);
        }

        dp = curr;
    }

    cout<<dp[0][0];
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
