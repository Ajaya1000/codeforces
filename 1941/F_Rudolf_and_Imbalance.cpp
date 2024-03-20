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
    int n,m,k;cin>>n>>m>>k;

    ll a[n],b[m],c[k];

    for_each(v,a) cin>>v;
    for_each(v,b) cin>>v;
    for_each(v,c) cin>>v;

    int maxxi;
    ll maxx,maxx2;
    maxxi = maxx = maxx2 = -1;

    rep(i,1,n-1) {
        if(a[i]-a[i-1] > maxx) {
            maxx2 = maxx;
            maxx = a[i]-a[i-1];
            maxxi = i;
        } else {
            maxx2 = max(maxx2,a[i]-a[i-1]);
        }
    }

    sort(b,b+m);
    sort(c,c+k);

    ll mid = (a[maxxi]+a[maxxi-1]) / 2;

    ll minn = maxx;

    for_each(v,b) {
        auto t = upper_bound(c,c+k,mid-v);
        int i = (t-c);
        
        rep(j,i-1,i) {
            if(j>=k || j<0) continue;
            ll temp = c[j]+v;

            if(temp >= a[maxxi] && temp <= a[maxxi-1]) continue;

            minn = min(minn, max(a[maxxi] - temp, temp - a[maxxi-1]));
        }
    }

    cout<<max(maxx2,minn);
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