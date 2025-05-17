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
    int n,l,r; cin>>n>>l>>r; l--,r--;
    ll a[n]; arr_in(a);
    vector<ll> left, mid, right;

    rep(i,0,l-1) left.pb(a[i]);
    rep(i,l,r) mid.pb(a[i]);
    rep(i,r+1,n-1) right.pb(a[i]);

    sort(left.begin(), left.end());
    sort(mid.begin(), mid.end()); reverse(mid.begin(), mid.end());
    sort(right.begin(), right.end());

    ll sum = 0;
    for_each(v,mid) sum+=v;

    ll minn = sum;

    ll curr = sum;

    for(int i = 0; i<min(left.size(), mid.size()) && mid[i] > left[i]; i++) {
        curr -= mid[i] - left[i];
        minn = min(minn,curr);
    }

    curr = sum;
    for(int i = 0; i<min(right.size(), mid.size()) && mid[i] > right[i]; i++) {
        curr -= mid[i] - right[i];
        minn = min(minn,curr);
    }

    cout<<minn;
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
