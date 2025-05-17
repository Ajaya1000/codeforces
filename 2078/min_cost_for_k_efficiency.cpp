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
    int n; cin>>n;
    ll k; cin>>k;
    ll a[n]; arr_in(a); //efficiency
    ll cost[n]; arr_in(cost);

    vector<vector<int>> vec(2);

    rep(i,0,n-1) {
        vec[cost[i]-1].pb(a[i]);
    }

    sort(vec[0].begin(), vec[0].end(), greater<int>());
    sort(vec[1].begin(), vec[1].end(), greater<int>());

    int l0 = vec[0].size();
    int l1 = vec[1].size();

    rep(i,1, l0 - 1) vec[0][i] += vec[0][i-1];

    ll mn = INT_MAX;

    int j = l0 - 1;
    while(j >= 0 && vec[0][j]>=k) {
        mn = min(mn,(ll)j+1);
        j--;
    }

    ll curr = 0;
    rep(i,0, l1 - 1) {
        curr+= vec[1][i];

        if(curr >= k) {
            mn = min(mn, 2ll * (i+1));
            continue;
        }

        while(j >= 0 && curr + vec[0][j] >= k) {
            mn = min(mn, 2ll * (i+1) + 1ll + j);
            j--;
        }
    }

    cout<<mn;
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