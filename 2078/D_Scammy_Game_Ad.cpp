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

void solve()
{
    int n; cin>>n;
    vector<vector<pair<char, int>>> vec(n);

    rep(i,0,n-1) {
        rep(j,0,1) {
            char ch;
            int x;
            cin>>ch>>x;
            vec[i].pb({ch,x});
        }
    }

    auto mul = [&] (int i, int j) -> ll {
        if(vec[i][j].first == 'x') return vec[i][j].second;
        return 1;
    };

    auto add = [&] (int i, int j) -> ll {
        if(vec[i][j].first == '+') return vec[i][j].second;
        return 0;
    };

    vector<vector<ll>> dp(n+1, vector<ll>(2));
    dp[n] = {1,1};

    repi(i,n-1,0) {
        rep(j,0,1) {
            dp[i][j] = max(dp[i+1][0], dp[i+1][1]) * (mul(i, j) - 1) + dp[i+1][j];
        }
    }

    ll tot = dp[0][0] + dp[0][1];

    rep(i,0,n-1) {
        ll extra = 0;

        rep(j,0,1) {
            extra += add(i,j);
        }

        tot += extra * max(dp[i+1][0], dp[i+1][1]);
    }

    cout<<tot;
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
