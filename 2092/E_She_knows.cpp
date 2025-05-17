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

ll _powMod(ll n, ll m)
{
    if (m == 0)
        return 1;

    ll res = _powMod(n, m / 2);

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
    ll n,m,k; cin>>n>>m>>k;
    ll border, border_black;
    border = border_black = 0;

    rep(_,0ll,k-1) {
        ll i,j,d;
        cin>>i>>j>>d;
        if( (i == 1 || i == n) && (j == 1 || j == m) ) continue;

        if(i == 1 || i == n || j == 1 || j == m) {
            border++;
            border_black += d;
        }
    }

    ll tot_border = (n+m-4) * 2ll;
    ll tot = n*m;

    ll p = tot - k;

    if(tot_border == border) {
        cout<<(border_black%2?0ll:_powMod(2ll, p));
    } else {
        cout<<_powMod(2ll, p-1);
    }
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
