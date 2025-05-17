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
    if (m == 0)
        return 1;
        
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

ll solve()
{
    int n; cin>>n;
    int count[2] = {0,0};
    ll a[n]; arr_in(a);
    ll tot = 0;
    ll maxx = 0;
    for_each(v,a) {
        count[v%2]++;
        maxx = max(maxx, v);
        tot+=v;
    }

    if(count[0] == 0 || count[1] == 0)  return maxx;
    return tot -= count[1] - 1;
}
int main()
{
    fastio;

    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}

rep(i,1,c[x[1]]-c[x[0]]) {
    if(i == 1) {
        seq.push_back(f[x[0]]?x[0]:x[1]);
        seq.push_back(f[x[0]]?x[1]:x[0]);
    }else {
        seq.push_back(x[0]);
        seq.push_back(x[1]);
    }

    seq.push_back(x[2]);
    seq.push_back(x[0]);
}