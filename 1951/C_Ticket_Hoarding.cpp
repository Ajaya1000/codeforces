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

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first < b.first;
}

void solve()
{
    ll n,m,k;cin>>n>>m>>k;

    ll a[n];
    for_each(v,a) cin>>v;

   vector<pair<ll,ll>> vec;

   rep(i,0,n-1) vec.push_back({a[i],i});

   sort(vec.begin(),vec.end(), comp);

//    for_each(p,vec) cout<<p.second<<" ";
//    cout<<endl;

   ll b[n];
   memset(b,0,sizeof(b));

   for_each(p,vec) {
    if(k == 0) break;
    ll x = min(m,k);
    k-=x;

    b[p.second] = x;
   }

   ll sum = 0;

   ll count = 0;
   rep(i,0,n-1) {
    // cout<<b[i]<<" ";
     sum += (ll)b[i] * ((ll)a[i] + count);

     count += (ll)b[i];
   }
//    cout<<endl;
   cout<<sum;
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
