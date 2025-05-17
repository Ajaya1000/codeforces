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
    ll n,l,r; cin>>n>>l>>r;

    vector<int> a(n+1);
    rep(i,1,n) cin>>a[i];

    vector<ll> p(n+1);
    rep(i,1,n) p[i] = p[i-1] + a[i];

    if(n%2 == 0) {
        n++;
        a.pb(p[n/2] & 1);
        p.pb(p.back() + a.back());
    }

    rep(i,n+1,2*n) {
        a.pb(p[i/2] & 1);
        p.pb(p.back() + a.back());
    }

    vector<ll> p0(2*n+1);

    for(int i=1;i<=2*n;i++) {
        p0[i] = p0[i-1];
        if(i%2==0) p0[i] += a[i];
    }

    function<int(ll)> getVal = [&](ll x) -> int {
        if(x <= n) return a[x];
        if(x<=2*n) return p[x/2] & 1;
        
        ll m = x/2;
        int r = p[n] & 1;

        if(m % 2 == 0) r ^= getVal(m);
        return r;
    };

    function<ll(ll)> getEvenSum = [&] (ll m) -> ll {
        if(m<=2*n) return p0[m];

        int pn = p[n] & 1;
        ll j = m/2;
        
        ll eSum = getEvenSum(j) - p0[n];
               
        ll both = eSum * (1ll-(2ll*pn)) + (ll)(j - n + 1) * (ll)pn;

        return p0[2*n - 1] + both;
    };

    auto getSum = [&] (ll m) -> ll {
        if(m<=2*n) return p[m];

        ll sum0 = getEvenSum(m);
    
        ll both = sum0 - p0[2*n-1];
                    /* Odd sum*/
        ll sum1 = (p[2*n-1] - p0[2*n-1]) + both;

        if(m % 2 == 0) {
            sum1 -= getVal(m+1);
        }

        return sum0+sum1;
    };

    cout<<getSum(r) - getSum(l-1);
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
