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

bool solve()
{
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    bool f0, f1, f;
    f = f0 = f1 = 0;

    rep(i, 1, n - 1) if (a[i] == a[i - 1]) if (a[i] == '0') f0 = 1;
    else f1 = 1;
    rep(i, 1, m - 1) if (b[i] == b[i - 1]) f = 1;

    if (!f0 && !f1)
        return 1;

    if (f || (f0 && f1) || (b[0] != b.back()) || (f0 && b[0] == '0') || (f1 && b[0] == '1'))
        return 0;

    return 1;
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