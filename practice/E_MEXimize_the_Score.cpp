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

ll modMul(ll a, ll b) {
    return (a*b)%mod;
}

ll modAdd(ll a, ll b) {
    return (a+b)%mod;
}


/*
    workplace start from here
*/
const int N = 2e5+5;
ll inv[N];

void pre() {
    inv[0]=inv[1]=1;

    rep(i,2,N-1) {
        inv[i] = modMul(mod-(mod/i), inv[mod%i]);
    }
}

void solve()
{
    int n; cin>>n;
    vector<int> f(n+1); 

    rep(_,0,n-1) {
        int v;cin>>v;
        f[v]++;
    }

    vector<int> m(n+1);
    m[0] = f[0];
    rep(i,1,n) m[i] = f[i];//min(f[i],m[i-1]);


    vector<vector<ll>> dp(n+1);

    vector<vector<ll>> comb(n+1);
     
    rep(i,0,n) {
        comb[i].pb(1);
        rep(j,1,f[i]) {
            comb[i].pb(modMul(modMul(comb[i].back(), (f[i]-j+1)), inv[j]));
        }
    }
     
    ll lst = 0;
    
    dp[0] = vector<ll>(m[0]+1);

    rep(j,0,m[0]) {
        dp[0][j] = comb[0][j];
        if(j>f[1]) lst = modAdd(lst, dp[0][j]);
    }

    rep(i,1,n) {
        dp[i] = vector<ll>(m[i]+1);

        ll pre1 = lst;
        ll pre2 = 0;

        lst = 0;
        repi(j,m[i],0) {
            pre2 = modAdd(pre2, comb[i][j]);
            dp[i][j] = modAdd(modMul(comb[i][j], pre1), modMul(j>f[i-1]?0:dp[i-1][j], pre2));
            pre1 = modAdd(pre1, j>f[i-1]?0:dp[i-1][j]);

            if(i+1<=n && j>f[i+1]) lst = modAdd(lst, dp[i][j]);
        }
    }

    ll suf = 1;
    ll ans = 0;
    
    repi(i,n,0) {
        ll tempSum = 0;
        rep(j,0,m[i]) tempSum = modAdd(tempSum, modMul(dp[i][j], j));
        ans = modAdd(ans, modMul(tempSum, suf));

        suf = modMul(suf, _powMod(2, f[i]));
    }

    cout<<ans;
    
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
