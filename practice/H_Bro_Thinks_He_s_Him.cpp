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
const int N=2e5+16;

vector<vector<vector<ModNum>>> dp(4*N, vector<vector<ModNum>>(2, vector<ModNum>(2)));
vector<vector<vector<ModNum>>> sum(4*N, vector<vector<ModNum>>(2, vector<ModNum>(2)));

void update(int i, int l, int r, int v, string &s) {
    if((v<l || v>r) && (v != -1)) return;

    // cout<<l<<" "<<r<<endl;

    if(l==r) {
        int j = s[l]-'0';
        sum[i][j][j] = dp[i][j][j] = 1;
        sum[i][j][1-j] = dp[i][j][1-j] = 0;
        sum[i][1-j][j] = dp[i][1-j][j] = 0;
        sum[i][1-j][1-j] = dp[i][1-j][1-j] = 0;

        return;
    }

    int m = l + (r-l) / 2;
    update(2*i+1,l,m,v,s);
    update(2*i+2,m+1,r,v,s);
    
    rep(x0,0,1) {
        rep(y0,0,1) {
            dp[i][x0][y0] = dp[2*i+1][x0][y0] + dp[2*i+2][x0][y0];
            sum[i][x0][y0] = sum[2*i+1][x0][y0] + sum[2*i+2][x0][y0];

            dp[i][x0][y0] += (dp[2*i+1][x0][0] + dp[2*i+1][x0][1]) * (dp[2*i+2][0][y0] + dp[2*i+2][1][y0]);

            sum[i][x0][y0] += (dp[2*i+1][x0][0] + dp[2*i+1][x0][1]) * (sum[2*i+2][0][y0] + sum[2*i+2][1][y0]) + 
                                (sum[2*i+1][x0][0] + sum[2*i+1][x0][1]) * (dp[2*i+2][0][y0] + dp[2*i+2][1][y0]);

            sum[i][x0][y0] -= dp[2*i+1][x0][0] * dp[2*i+2][0][y0] + dp[2*i+1][x0][1] * dp[2*i+2][1][y0];
        }
    }
}

void solve()
{
    string s; cin>>s;
    int n = s.size();


    update(0,0,n-1,-1,s);

    int q; cin>>q;
    while(q--) {
        int v; cin>>v; v--;

        if(s[v]=='0') s[v]='1';
        else s[v]='0';
        // cout<<endl<<"query "<<q<<endl;
        update(0,0,n-1,v,s);

        cout<<(sum[0][0][0]+sum[0][0][1]+sum[0][1][0]+sum[0][1][1])<<" ";
    }
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
