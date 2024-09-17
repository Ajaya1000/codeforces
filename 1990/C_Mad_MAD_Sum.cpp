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
inline ll _mul(ll a, ll b) {return (a*b); }
inline ll _div(ll a, ll b) {return (a/b); }

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

ll giveSum(vector<int> &a) {
    int n = a.size();

    ll sum = 0;
    for_each(v,a) sum+=(ll)v;

    int count[n+1];
    memset(count,0,sizeof(count));

    int maxx = 0;

    rep(i,0,n-1) {
        count[a[i]]++;
        if(a[i]>maxx && count[a[i]]>1) maxx = a[i];
        a[i] = maxx;
    }

    return sum;
}
void solve()
{
    int n;cin>>n;
    vector<int> a(n); arr_in(a);

    ll sum = 0;
    sum += giveSum(a);
    sum += giveSum(a);

    int prev = 0;
    int curr = 0;
    rep(i,0,n-1) {
        sum += _mul(n-i, a[i]);
    }

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
