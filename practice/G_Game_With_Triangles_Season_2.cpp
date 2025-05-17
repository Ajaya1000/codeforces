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

ll getMax(int l, int r, ll a[], vector<vector<ll>> &dp) {
    if(r-l+1 < 3) return 0ll;
    if(dp[l][r] != -1) return dp[l][r];

    ll maxx = getMax(l+1,r,a,dp);

    rep(i,l+1,r-1) {
        ll val = a[l] * a[i] * a[r] + getMax(l+1,i-1,a,dp) + getMax(i+1,r-1,a,dp);
        maxx = max(maxx,val);
        maxx = max(maxx, getMax(l,i,a,dp) + getMax(i+1,r,a,dp));
    }

    return dp[l][r] = maxx;
}
    
ll solve()
{
    int n; cin>>n;
    ll a[n]; arr_in(a);

    vector<vector<ll>> dp(n, vector<ll>(n, -1));

    return getMax(0, n-1, a, dp);
}
int main()
{
    fastio;

    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}
