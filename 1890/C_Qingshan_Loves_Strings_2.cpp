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
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n % 2)
    {
        cout << -1;
        return;
    }

    vector<int> vec;
    list<char> l(s.begin(), s.end());

    int f = 0;
    while (!l.empty())
    {
        if (l.front() != l.back())
        {
            l.pop_front();
            l.pop_back();
            f++;
            continue;
        }

        if (l.front() == '0')
        {
            vec.push_back(n - f);
            l.push_back('0');
            l.push_back('1');
        }
        else
        {
            vec.push_back(f);
            l.push_front('1');
            l.push_front('0');
        }

        n += 2;

        if (vec.size() > 300)
            break;
    }

    if (vec.size() > 300)
    {
        cout << -1;
        return;
    }

    cout << vec.size() << endl;
    for (auto &v : vec)
        cout << v << " ";
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