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
    string s[n]; arr_in(s);

    int r,c;
    r = c = 0;

    rep(i,0,n-1) {
        int x = 0;
        rep(j,0,m-1) if(s[i][j]=='1') x = 1 - x;
        r+=x;
    }

    rep(j,0,m-1) {
        int x = 0;
        rep(i,0,n-1)  if(s[i][j]=='1') x = 1 - x;
        c+=x;
    }

    cout<<r+c-min(r,c);
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
