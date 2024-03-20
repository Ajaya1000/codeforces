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

void solve()
{
    ll n,c;cin>>n>>c;

    ll a[n];

    ll x,y;
    x=y=0;
    
    ll sx,sx2;
    sx=sx2=0;

    for_each(v,a) {
         cin>>v;

         if(v%2) x++;
         else y++;

         sx+=v;
         sx2+=(v/2);
    }
    
    ll total = ((c+1) * (c+2)) / 2;

    ll syx = n*(c+1) - sx;
    ll syx2 = n+sx2;

    ll sumx = (x*(x+1)) / 2;
    ll sumy = (y*(y+1)) / 2;

    ll ans = total - syx - syx2 + sumx+sumy;
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