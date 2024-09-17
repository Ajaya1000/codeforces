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
    int n; cin>>n;
    ll k; cin>>k;

    int a[n];arr_in(a);
    int b[n];arr_in(b);

    vector<int> ind(n);
    rep(i,0,n-1) ind[i]=i;
    sort(ind.begin(),ind.end(),[&](int i, int j) {
        return (a[i]<a[j]);
    });

    int maxxi = -1;
    rep(i,0,n-1) if(b[ind[i]]) maxxi = i;

    auto getMax = [&](int pos) {
        int mid = (n/2) - 1;
        if(mid >= pos) mid++;
        return (ll)a[ind[pos]] + (ll)a[ind[mid]];
    };

    ll maxx = getMax(n-1);
    
    if(maxxi == -1) {
        cout<<maxx;
        return;
    }

    if(a[ind[maxxi]]+k >= a[ind[n-1]]) maxx= max(maxx,getMax(maxxi) + k);

    ll lo = 0;
    ll hi = 1e9+1;

    while(lo<hi) {
        ll mid = lo + ((hi-lo) / 2ll);

        int z = 0;
        ll curr = k;
    
        repi(i,n-2,0) {
            if(a[ind[i]]>=mid) z++;
            else if(b[ind[i]] && curr>=(mid-a[ind[i]])) {
                z++;
                curr-=(mid-a[ind[i]]);
            }
        }

        if(z>=((n+1)/2)) {
            maxx = max(maxx, a[ind[n-1]] + mid);

            lo=mid+1;
        } else {
            hi = mid;
        }
    }

    cout<<maxx;
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
