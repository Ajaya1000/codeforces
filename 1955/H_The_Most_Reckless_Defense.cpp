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

const int N = 12;

ll p3[N+1];

void pre()
{
    p3[0] = 1;

    rep(i, 1, N) p3[i] = p3[i - 1] * 3ll;

    p3[0] = 0; // base case will be zero
}

int giveRad(int u, int v, int i, int j)
{
    ll d1 = abs(u - i);
    ll d2 = abs(v - j);

    ll r2 =  d1*d1 + d2*d2;

    ll r = sqrt(r2);

    if(r*r == r2) return r;

    return r+1;
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    string s[n];
    for_each(v, s) cin >> v;

    int u, v, p;

    vector<ll> mat(k);

    ll ans = 0;

    vector<vector<ll>> count(k,vector<ll>(N+1,0));

    rep(x, 0, k - 1)
    {
        cin >> u >> v >> p;

        u--, v--;

        rep(i, 0, n - 1)
        {
            rep(j, 0, m - 1)
            {

                auto r = giveRad(u, v, i, j);
                assert(r < N);
                if(s[i][j] == '#') count[x][r]++;
            }
        }

        ll sum = 0;

        ll maxx = 0;
        int maxr = 0;
        rep(i, 0, N - 1)
        {
            auto val = count[x][i];

            if(i == 0) count[x][i] = 0;
            else  count[x][i] = count[x][i-1];

            count[x][i] += val * (ll)p;
        }

        cout<<maxx<<" "<<maxr<<"\t";
        ans += maxx;
    }

    cout<<endl;
    cout << ans;
}
int main()
{
    fastio;

    pre();
    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
