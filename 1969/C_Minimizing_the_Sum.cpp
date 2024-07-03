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

ll giveValue(int i, int k, ll a[], vector<vector<ll>> &dp) {
    int n = dp.size();
    if(i >= n) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    ll curr = LLONG_MAX;
    ll minn = LLONG_MAX;

    rep(x,0,k) {
        if(i+x >= n) break;
        curr = min(curr, a[i+x]);
        ll val = curr*(1ll+x) + giveValue(i+x+1,k-x,a,dp);
        // cout<<i<<" "<<x<<" val "<<val<<" "<<giveValue(i+x+1,k-x,a,dp)<<endl;
        minn = min(minn, val);
    }

    // cout<<i<<" "<<k<<" "<<minn<<endl;
    return dp[i][k] = minn;
}

void solve()
{
    int n,k;cin>>n>>k;

    ll a[n];
    arr_in(a);

    vector<vector<ll>> dp(n, vector<ll>(k+1, -1));

    ll suf = 0;
    repi(i,n-1,0) {
        suf += a[i];
        dp[i][0] = suf;
    }

    cout<<giveValue(0,k,a,dp);
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
