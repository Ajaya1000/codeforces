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
    int l,n,m; cin>>l>>n>>m;
    int a[l]; arr_in(a);
    int b[n][m];
    rep(i,0,n-1) arr_in(b[i]);

    u_map<int, int> ind;

    rep(i,0,l-1) {
        if(ind.find(a[i]) != ind.end()) break;
        ind[a[i]] = i;
    }

    int dp[2][n][m];
    rep(i,0,n-1) rep(j,0,m-1) dp[0][i][j]=dp[1][i][j]=INT_MAX;

    repi(i,n-1,0) {
        repi(j,m-1,0) {
            if(i+1<n) {
                dp[0][i][j] = min(dp[0][i][j], dp[0][i+1][j]); 
                dp[1][i][j] = min(dp[1][i][j], dp[1][i+1][j]);
            }

            if(j+1<m) {
                dp[0][i][j] = min(dp[0][i][j], dp[0][i][j+1]); 
                dp[1][i][j] = min(dp[1][i][j], dp[1][i][j+1]);
            }

            if(ind.find(b[i][j]) == ind.end()) continue;

            int curr = ind[b[i][j]];
            int p =  curr%2;

            if(i+1 >= n || j+1 >= m || dp[1-p][i+1][j+1]>(curr+1)) dp[p][i][j] = min(dp[p][i][j],curr);
        }
    }
    
    if(dp[0][0][0] == 0) cout<<"T";
    else cout<<"N";
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
