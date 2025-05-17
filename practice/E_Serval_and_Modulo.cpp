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

const ll MAXX = 1e6+5;

ll solve()
{
    int n; cin>>n;
    ll a[n],b[n];
    arr_in(a);
    arr_in(b);
    sort(b,b+n);

    ll sum = 0;
    for_each(v,a) sum += v;
    for_each(v,b) sum -= v;

    auto check = [&] (ll x) -> bool {
        ll c[n];
        rep(i,0,n-1) c[i] = a[i] % x;
        sort(c,c+n);
        rep(i,0,n-1) {
            if(c[i] != b[i]) return 0;
        }

        return 1;
    };

    if(sum <= 0) {
        if(check(MAXX)) return MAXX;
    }

    for(ll x=1;x*x<=sum;x++) {
        if(sum%x) continue;

        if(check(x)) return x;
        if(check(sum/x)) return sum/x;
    }

    return -1;
}
int main()
{
    fastio;

    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}
