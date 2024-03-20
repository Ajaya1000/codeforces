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

int solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> st;

    rep(i, 0, n - 1)
    {
        while (st.size() && s[st.back()] < s[i])
            st.pop_back();
        st.push_back(i);
    }

    int m = st.size();

    // calculating C
    int c = 0;
    rep(i, 0, m - 1)
    {
        if (s[st[0]] == s[st[i]])
            c++;
        else
            break;
    }

    // swaps
    for (int i = 0; i < m / 2; i++)
    {
        int x = st[i];
        int y = st[m - 1 - i];

        swap(s[x], s[y]);
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] > s[i])
            return -1;
    }

    return (m - c);
}
int main()
{
    fastio;

    test
    {
        cout << solve();
        cout << endl;
    }

    return 0;
}