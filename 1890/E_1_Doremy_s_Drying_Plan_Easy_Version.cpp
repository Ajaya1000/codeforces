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

// struct comp
// {
//     bool operator()(pii a, pii b) const
//     {
//         return a.first < b.first;
//     }
// };

bool func(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

int findmax2sum(int t[], int m)
{
    int a = -1;
    int b = -1;

    rep(i, 0, m - 1)
    {
        if (a <= t[i])
        {
            b = a;
            a = t[i];
        }
        else if (b <= t[i])
        {
            b = t[i];
        }
    }

    return a + b;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> vec(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> vec[i][0] >> vec[i][1];
        vec[i][0]--, vec[i][1]--;
        vec[i][2] = i;
    }

    sort(vec.begin(), vec.end(), func);

    set<pii> s;

    u_map<ll, int> mp;
    int t[m];
    memset(t, 0, sizeof(t));

    int j = 0;
    int lft = 0;
    rep(i, 0, n - 1)
    {
        // cout << " in " << i << endl;
        while (s.size() && s.begin()->first < i)
        {
            // cout << "remove " << endl;
            s.erase(s.begin());
        }

        while (j < m && vec[j][0] <= i)
        {
            // cout << "insert " << vec[j][1] << " " << vec[j][2] << endl;
            s.insert({vec[j][1], vec[j][2]});
            j++;
        }

        // cout << "size " << s.size() << endl;

        if (s.size() == 0)
        {
            lft++;
        }
        else if (s.size() == 1)
        {
            t[s.begin()->second]++;
        }
        else if (s.size() == 2)
        {
            ll i1 = s.begin()->second;
            ll i2 = (++s.begin())->second;

            if (i1 > i2)
                swap(i1, i2);
            mp[i1 * m + i2]++;
        }
    }

    int maxx = 0;

    for_each(v, mp)
    {
        int i1 = v.first / m;
        int i2 = v.first % m;

        maxx = max(maxx, v.second + t[i1] + t[i2]);
    }

    // for_each(v, t) cout << v << " ";
    // cout << "\t";
    cout << lft + max(maxx, findmax2sum(t, m));
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