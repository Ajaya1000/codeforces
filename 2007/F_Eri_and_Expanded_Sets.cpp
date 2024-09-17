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
#define int  long long
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

bool isPowerofTwo(int n)
{
    if(n==0) return 0;
    return (n & (n - 1)) == 0;
}

void solve()
{
    int n; cin>>n;
    int a[n];arr_in(a);

    vector<vector<int>> sp(log2(n)+1,vector<int>(n-1));
    rep(j,0,n-2) sp[0][j] = abs(a[j] - a[j+1]);

    int lsteq[n];
    lsteq[n-1] = n-1; 
    repi(i,n-2,0) {
        lsteq[i] = (a[i] == a[i+1]? lsteq[i+1] : i);
    }

    rep(i,1,log2(n)) rep(j,0,n-1-(1<<i)) {
        sp[i][j] = gcd(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
    }

    auto query = [&](int l, int r) {
        int sz = log2(r-l+1);
        return gcd(sp[sz][l], sp[sz][r-(1<<sz)+1]);
    };

    int l = 0;
    int r = 0;

    int ans = 1;
    rep(i,0,n-2) {
        l = max(l, lsteq[i]);
        r = max(r,l);

        while(r<n-1 && !isPowerofTwo(query(l,r))) r++;
        ans+=(n-1-r); ans+=(lsteq[i]-i+1);
    }

    cout<<ans;
}
signed main()
{
    fastio;

    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
