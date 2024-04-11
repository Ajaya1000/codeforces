// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
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
bool isValid(int i,int j,int n) {
    return (i>=0 && i<2 && j>=0 && j<n);
}

bool can(int i,int j, int n, string mat[], vector<vector<int>> &dp) {
    if(i == 1 && j == n-1) return 1;
    if(dp[i][j] >= 0) return dp[i][j];

    dp[i][j] = -2;

    vector<pii> vec;

    if(isValid(i+1,j,n)) vec.pb({i+1,j});
    if(isValid(i-1,j,n)) vec.pb({i-1,j});
    if(isValid(i,j+1,n)) vec.pb({i,j+1});
    if(isValid(i,j-1,n)) vec.pb({i,j-1});

    for_each(p,vec) {
        int x = p.ff,y =p.ss;

        if(mat[x][y] == '<') y--;
        else y++;

        if(dp[x][y] == -2) continue;

        if(can(x,y,n,mat,dp)) {
            return dp[i][j] = 1;
        }
    }

    return dp[i][j] = 0;
}

void solve()
{
    int n;cin>>n;

    string mat[2];

    cin>>mat[0]>>mat[1];

    vector<vector<int>> dp(2,vector<int>(n,-1));

    cout<<(can(0,0,n,mat,dp) ? "YES": "NO");
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