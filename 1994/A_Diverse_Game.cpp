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
    int n,m;cin>>n>>m;
    int a[n][m];

    rep(i,0,n-1) rep(j,0,m-1) cin>>a[i][j];

    if(n == 1 && m == 1) {
        cout<<-1<<endl;
        return;
    }

    if(m>1) {
        rep(i,0,n-1) {
            rep(j,0,(m/2) - 1) swap(a[i][j],a[i][m-1-j]);
            if(m%2) swap(a[i][m/2],a[i][0]);
        }
    } else {
        rep(j,0,m-1) {
            rep(i,0,(n/2) - 1) swap(a[i][j],a[n-1-i][j]);
            if(n%2) swap(a[n/2][j],a[0][j]);
        }
    }

    rep(i,0,n-1){ 
        rep(j,0,m-1) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    fastio;

    test
    {
        solve();
        // cout << endl;
    }

    return 0;
}
