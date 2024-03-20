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
const int N = 100;
const int v[] = {1,3,6,10,15};

ll dp[N+1];
void pre() {
    dp[0] = 0;

    rep(i,1,N) {
        dp[i] = i;
        rep(j,0,4) {
            if(i-v[j]>=0) {
                dp[i] = min(dp[i],1+dp[i-v[j]]);
            }
        }
     }
}
void solve()
{
    ll n;cin>>n;
    ll d = n/15;

    d = max(0ll,d-5);

    // cout<<(n-d*15l)<<"\t";
    cout<<d+dp[n-d*15ll];
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