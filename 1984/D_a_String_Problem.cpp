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

void solve()
{
    string s;cin>>s;

    int n = s.size();
    int a[n];

    int lst = n;
    repi(i,n-1,0) {
        if(s[i] != 'a') lst = i;
        a[i] = lst;
    }

    if(a[0] == n) {
        cout<<(n-1);
        return;
    }

    int z[n];
    memset(z,0,sizeof(z));

    int l,r;
    l = r = a[0];
    rep(i, a[0]+1, n-1) {
        if(i<=r) {
            z[i] = min(r-i+1, z[i-l]);
        }

        while(i+z[i]<n && s[i+z[i]] == s[a[0]+z[i]]) z[i]++;

        if(i+z[i]-1 > r) {
            l = i;
            r = i+z[i]-1;
        }
    }

    ll ans = 0;

    int minna;
    rep(t,1,n-a[0]) {
        minna = a[0];

        int curr = a[0]+t;
        bool flag = 1;

        while(curr < n) {
            if(a[curr] == n) break;

            minna = min(minna, a[curr]-curr);

            if(z[a[curr]] < t) {
                flag = 0;
                break;
            }

            curr = a[curr] + t;
        }

        if(flag) ans+=ll(minna+1);
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
