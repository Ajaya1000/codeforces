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
    int n,m; cin>>n>>m;
    ll k; cin>>k;

    vector<vector<ll>> mat(n,vector<ll>(m));
    for_each(vec,mat) arr_in(vec);

    vector<ll> dp(m, LLONG_MAX);
    dp[m-1] = 0;

    auto getJ = [&] (int r, int j) {
        return (j+r) % m;
    };

    repi(i,n-1,0) {
        vector<vector<ll>> curr(m, vector<ll>(m,LLONG_MAX));

        vector<ll> nxt(m);
        repi(j,m-1,0) {
            ll g_minn = LLONG_MAX;
            rep(r,0,m-1) {
                int j1 = getJ(r,j);

                ll minn;
                if(dp[j] == LLONG_MAX) minn = LLONG_MAX;
                else minn = k*(ll)r + dp[j];

                if(j+1 < m) minn = min(minn, curr[j+1][r]);
                
                minn += mat[i][j1];

                curr[j][r] =  minn;
                g_minn = min(g_minn, curr[j][r]);
            }

            nxt[j] = g_minn;
        }

        dp = nxt;

        // for_each(v, dp) cout<<v<<" ";
        // cout<<endl;
    }

    cout<<dp[0];
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
