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

ull pow2(int n, ull p) {
    if(n==0) return (ull)1;

    ull res = pow2(n/2,p);
    res = (res*res) % p;

    if(n%2) res = (res * (ull) 2) % p;

    return res;
}

void solve()
{
    int n,k;cin>>n>>k;
    ull p; cin>>p;

    ull inv[k+1];
    inv[0] = inv[1] = 1;
    rep(i,2,k) inv[i] = ((p - (p/i)) * inv[p%i]) % p;
    
    vector<vector<ull>> dp(n+1, vector<ull>(k+1,0));
    rep(i,0,k) dp[1][i]=1;

    rep(i,2,n) {
        ull y = pow2(i-1,p)-2;
        vector<ull> c(k+1);
        vector<ull> g(k+1);

        g[0] = c[0] = 1;
        rep(x,1,k) {
            c[x] = (c[x-1] * (((x+y) * inv[x])% p))  % p;
            g[x] = (c[x] + g[x-1]) % p;
        }

        rep(x,1,k) {
            rep(y,1,x) {
                dp[i][x] = (dp[i][x] + ((dp[i-1][y]) * g[min(y-1, x-y)]) % p) % p;
            }
        }
     }

    ull ans = (dp[n][k] * pow2(n-1,p)) % p;
    cout<<ans;
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
