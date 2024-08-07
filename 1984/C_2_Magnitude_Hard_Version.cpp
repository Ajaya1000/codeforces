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

#define mod 998244353

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

const int N = 2e5 + 1;

ll p[N];
void pre() {
    p[0] = 1;
    rep(i,1,N-1) p[i] = (p[i-1] * 2ll) % mod;
}

void solve()
{
    int n;cin>>n;
    int a[n];
    for_each(v,a) cin>>v;

    ll sum = 0;
    ll minn = 0;
    rep(i,0,n-1) sum+=a[i], minn = min(minn, sum);

    if(minn == 0) {
        cout<<p[n];
        return;
    } 

    sum = 0;

    ll cnt = 0;

    ll ans = 0;
    rep(i,0,n-1) {
        sum+=a[i];
        if(sum == minn) {
            ans = (ans + p[n-i-1+cnt]) % mod;
        }

        if(sum >= 0) cnt++;
    }

    cout<<ans;
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
