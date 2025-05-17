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
#define B 60
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
const ll INF = 1e18;

ll p[B];
vector<vector<ll>> dp(B,vector<ll>(B,INF));

void pre() {
    p[0] = 1;
    rep(i,1,B-1) p[i] = p[i-1] * 2ll;

    dp[0][0] = 0;
    for(int x=0;x<B;x++) {
        for(int i=B-1;i>=0;i--) {
            for(int j=B-1;j>=0;j--) {
                if(i-x >=0 ) dp[i][j] = min(dp[i][j], dp[i-x][j] + (1ll << x));
                if(j-x >=0 ) dp[i][j] = min(dp[i][j], dp[i][j-x] + (1ll << x));
            }
        }
    }
}

void solve()
{
    ll a,b; cin>>a>>b;

    ll minn = INF;
    repi(i,B-1,0) {
        repi(j,B-1,0) {
            if((a >> i) == (b>>j)) {
                minn = min(minn, dp[i][j]);
            }
        }
    }

    cout<<minn;
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
