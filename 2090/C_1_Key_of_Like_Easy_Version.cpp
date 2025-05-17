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

const int N = 5000;

ModNum inv[N+1];

void pre() {
    inv[0] = inv[1] = 1;
    rep(i,2,N) inv[i] = inv[mod%i] * (mod - (mod/i));
}

void solve()
{
    int n,l,k; cin>>n>>l>>k;

    
    vector<ModNum> dp(n,0);
    dp[0] = 1;

    rep(i,2,l) {
        vector<ModNum> curr(n,0);
        ModNum lst =  1;

        ModNum tot = 0;
        for_each(v, dp) tot += v;

        ModNum p_success = inv[i];

        rep(j,0,n-1) {
            curr[j] +=  p_success * (tot + 1ll) * (ll)(i/n);
        }

        int r = i%n;

        if(r) {

            ModNum currSum = 0;
            rep(j,0,r-1) currSum += dp[n-j-1];

            int l1 = n-r;
            int r1 = n-1;

            rep(j, 0, n-1) {
                if(j<r) curr[j] += p_success;
                curr[j] += p_success * currSum;

                currSum -= dp[l1];
                l1 = (l1+1) % n;
                r1 = (r1+1) % n;
                currSum += dp[r1];
            }
        }

        dp = curr;
    }

    for_each(v, dp) cout<<v<<" ";

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
