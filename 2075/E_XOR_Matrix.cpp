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

ll _powMod(ll n, ll m)
{
    if (m == 0)
        return 1;

    ll res = _powMod(n, m / 2);

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

ll nc2(ll x) {
    return (x * (x-1ll)) / 2ll;
}

int getRBitPos(ll a) {
    int i = 0;

    while (a)   
    {
        i++;
        a = a>>1;
    }
    
    return i;
}

ll getNumWithBitCount(int i) {
    ll a=0;
    while(i) {
        a = (a << 1) + 1ll;
        i--;
    }

    return a;
}
const int N = 30;

ModNum p[N+1];
void pre() {
    p[0] = 0;

    ll x = 1;
    ll a = 0;

    for(int i=1;i<=N;i++) {
        a = (a << 1) + 1ll;
        p[i] = p[0] + ModNum(a+1) * ModNum(a+1) * ModNum(x);
        x = x<<1;
    }
}

void solve()
{
    ll n,m,a,b; cin>>n>>m>>a>>b;

    a+=1ll;
    b+=1ll;

    ModNum case1 = ModNum(1) * a * b;
    ModNum case2 = (ModNum(_powMod(2,m)) - 2ll) * a * nc2(b);
    ModNum case3 = (ModNum(_powMod(2,n)) - 2ll) * b * nc2(a);

    a-=1ll;
    b-=1ll;

    if(b<a) swap(a,b);

    int i = getRBitPos(a);
    int j = getRBitPos(b);

    ll c = getNumWithBitCount(i);

    if(j > i) {
        b = c;
    }

    ll l = getNumWithBitCount(i-1);

    ll n1 = c-l;

    ModNum xa = a*2ll - c + 1;
    ModNum xb = b*2ll - c + 1;

    ModNum case4 = xa*xb*(n1);
    case4 += p[i-1];
    case4 /= 4;

    case4 *= (ModNum(_powMod(2,n)) - 2ll) * (ModNum(_powMod(2,m)) - 2ll);

    cout<<(case1+case2+case3+case4);
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
