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
bool func(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second > b.second;
}
bool solve()
{
    ll n, c;
    cin >> n >> c;
    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = a[i].first - (i + 1) * c;
    }

    if (n == 1)
        return true;

    sort(a.begin() + 1, a.end(), func);

    for (ll i = 1; i < n; i++)
    {
        if (a[i].second + a[0].first < 0)
            return false;

        a[0].first += a[i].first;
    }

    return true;
}
int main()
{
    fastio;

    test
    {
        cout << (solve() ? "Yes" : "No");
        cout << endl;
    }

    return 0;
}