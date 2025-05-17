// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio				   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);				  \
    cout.tie(0)
#define test  \
    int t;   \
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
    int n,k; cin>>n>>k;
    vector<pii> a;
    vector<int> b(n);
    rep(i,0,n-1) {
        int v; cin>>v;
        a.pb({v,i});
        b[i] = v;
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int p[n]; memset(p,-1,sizeof(p));

    rep(i,0,k-1) p[a[i].second] = k-i-1;

    int maxx = 0;

    repi(i,n-1,0) {
        if(p[i] != -1) {
            maxx = max(maxx,p[i]);
        } else {
            p[i] = maxx;
        }
    }

    int d[n]; memset(d,0,sizeof(d));

    vector<ll> res(k);

    rep(i,0,n-1) {
        // cout<<p[i]<<" ";
        d[p[i]]++;
        res[p[i]] = max(res[p[i]], (ll)d[p[i]] + (ll)b[i]);
    }

    cout<<endl;

    ll sum = 0;
    for_each(v,res) {
        // cout<<v<<" ";
        sum+=v;
    }
    // cout<<endl;

    cout<<sum;
}
int main()
{
    fastio;

    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}