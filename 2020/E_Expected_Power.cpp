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

ull _mulMod(ull a, ull b) {
    return ((a%mod)*(b%mod))%mod;
}

ull _addMod(ull a, ull b) {
    return ((a%mod)+(b%mod))%mod;
}

/*
    workplace start from here
*/
const int N=1023;
const int C=1e4;
const int Ci = _powMod(C, mod-2);

void solve()
{
    int n; cin>>n;
    int a[n]; arr_in(a);
    int p[n]; arr_in(p);

    vector<ll> res(N+1,0);
    res[0] = 1;

    
    rep(i,0,n-1) {
        vector<ll> curr(N+1,0);

        rep(j,0,N) {
            // not included
            curr[j] += _mulMod(res[j], _mulMod(C-p[i],Ci));

            // included
            curr[j^a[i]] += _mulMod(res[j], _mulMod(p[i],Ci));
        }

        res = curr;
    }

    ll ans=0;
    rep(i,0,N) {
        ans = _addMod(ans, _mulMod(_powMod(i,2), res[i]));
    }

    cout<<ans;
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
