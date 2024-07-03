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

int divup(int a, int b) {
    return (a+b-1) / b;
}


void solve()
{
    int n,m;cin>>n>>m;

    int a[n], b[n], c[m];

    int maxxa = -1;
    for_each(v,a) {
        cin>>v;
        maxxa = max(maxxa,v);
    }
    arr_in(b);
    arr_in(c);

    int best[maxxa+1];
    rep(i,0,maxxa) best[i] = INT_MAX;

    rep(i,0,n-1) {
        best[a[i]] = min(best[a[i]],a[i]-b[i]);
    }

    rep(i,1,maxxa) {
        best[i] = min(best[i], best[i-1]);
    }

    ll dp[maxxa+1];
    auto giveDP = [&dp](int i) {
        if(i<0) return -2ll;

        return dp[i];
    };

    rep(i,0,maxxa) {
        dp[i] = giveDP(i-best[i]) + 2ll;
    }

    ll ans = 0;
    for_each(v,c) {
        if(v>=maxxa) {
            ll x = divup((v-maxxa), best[maxxa]);
            v -= best[maxxa] * x;

            x*=2;
            ans+=x;
        }

        // assert(v<maxxa);
        ans+=giveDP(v);
    }

    cout<<ans<<" ";
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
