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

void solve()
{
    int n; cin>>n;
    vector<vector<int>> mat(n);

    rep(i,1,n-1) {
        int j; cin>>j; j--;
        mat[j].push_back(i);
    }

    vector<int> count(n);

    function<void(int,int)> dfs = [&] (int u, int d) {
        count[d]++;
        for_each(v, mat[u]) dfs(v,d+1);
    };

    dfs(0,0);

    ll dp[n];
    dp[0] = 1;
    rep(i,1,n-1) dp[i] = (dp[i-1] * (ll) (count[i] - 1)) % mod;

    ll ans = 1;

    rep(i,1,n-1) {
        if(count[i] == 0) break;

        ans = (ans + (count[i] * dp[i-1]) % mod) % mod;
    }
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
