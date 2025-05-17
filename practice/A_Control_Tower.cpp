// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio				   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);				  \
    cout.tie(0)
#define test  \
    int t;   \
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
    int n,m; cin>>n>>m;
    vector<string> s(n); arr_in(s);

    vector<int> r(n);
    vector<int> c(m);

    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(s[i][j] == '.') r[i]++,c[j]++;
        }
    }

    ll ans = 0;

    rep(i,0,n-1) {
        ll s1,s2,rc;
        rc = s1 = s2 = 0;
        rep(j,0,m-1) {
            assert(i<n && j<m);
            if(s[i][j] == '#') continue;
            rc++;
            s1 += (c[j] - 1);
            s2 += (ll)(c[j]-1) * (ll) (c[j]-1);
        }

        if(rc<2) continue;
        ans += (s1 * s1) - s2 + (2ll * s1 * (rc-1) * (rc-2)) + (rc * (rc-1) * (rc-2) * (rc-3));

        // cout<<i<<":"<<s1<<":"<<s2<<":"<<rc<<":"<<ans<<" ";
    }
    // cout<<endl;

    rep(j,0,m-1) {
        ll s1,s2,rc;
        rc = s1 = s2 = 0;

        rep(i,0,n-1) {
            assert(i<n && j<m);
            if(s[i][j] == '#') continue;
            rc++;
            s1 += (r[i] - 1);
            s2 += (ll)(r[i] - 1) * (ll)(r[i] - 1);
        }
        if(rc<2) continue;
        ans += (s1 * s1) - s2 + (2ll * s1 * (rc-1) * (rc-2)) + (rc * (rc-1) * (rc-2) * (rc-3));
        // cout<<j<<":"<<s1<<":"<<s2<<":"<<rc<<":"<<ans<<" ";
    }
    // cout<<endl;

    cout<<ans;
}
int main()
{
    fastio;

    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}