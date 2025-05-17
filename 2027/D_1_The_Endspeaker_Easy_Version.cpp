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

void solve()
{
    int n,m; cin>>n>>m;

    ll a[n]; arr_in(a);
    ll b[m]; arr_in(b);

    rep(i,1,n-1) a[i] += a[i-1];

    vector<vector<ll>> dp(m, vector<ll>(n,-1));

    //i for b & j for a
    function<ll(int, int)> getMin = [&] (int i, int j) -> ll {
        if(i>=m) return LLONG_MAX;
        if(j>=n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        ll curr = b[i] + (j>0?a[j-1]:0);

        auto c = upper_bound(a+j,a+n,curr);
        auto nxt_j = (c-a);

        if(nxt_j == j) return LLONG_MAX;

        auto ans1 = getMin(i, nxt_j);
        if(ans1 != LLONG_MAX) ans1+=(long)(m-i-1);

        auto ans2 = getMin(i+1,j);

        return dp[i][j] = min(ans1, ans2);
    };

    auto ans = getMin(0,0);
    if(ans == LLONG_MAX) cout<<-1;
    else cout<<ans;

    // rep(i,0,m-1) {
    //     rep(j,0,n-1) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
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
