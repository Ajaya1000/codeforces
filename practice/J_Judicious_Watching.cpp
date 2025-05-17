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
    int n,m,q; cin>>n>>m>>q;

    vector<ll> a(n),d(n),l(m);
    arr_in(a);
    arr_in(d);
    arr_in(l);
    vector<ll> pre_l(m);
    pre_l[0] = l[0];
    rep(i,1,m-1) pre_l[i] = pre_l[i-1] + l[i];

    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);

    sort(ind.begin(), ind.end(), [&](int i, int j) {
        return d[i] < d[j];
    });

    vector<ll> end(n);
    vector<ll> start(n);
    ll lst_start = LLONG_MAX;

    repi(i,n-1,0) {
        end[i] = min(lst_start, d[ind[i]]);
        lst_start = end[i] - a[ind[i]];
        start[i] = lst_start;
    }

    vector<ll> pre_time(n);

    rep(i,0,n-1) {
        pre_time[i] = a[ind[i]] + (i>0?pre_time[i-1]: 0);
    }

    ll tx;
    while(q--) {
        cin>>tx;

        auto it = lower_bound(start.begin(), start.end(), tx);// start[i] <= tx
        int i = it - start.begin(); i--; // start[i] < tx

        ll time_left;
        if(i<0) {
            time_left = tx;
        } else {
            ll bound = max(tx, end[i]);
            time_left = bound - pre_time[i];
        }

        auto it2 = upper_bound(pre_l.begin(), pre_l.end(), time_left);
        int j = it2 - pre_l.begin(); j--;
        cout<<j+1<<" ";
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
