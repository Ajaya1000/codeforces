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
    int n; cin>>n;
    ull a[n]; arr_in(a);

    ull l = 0;
    ull r = 1e12;
 
    while(l<r) {
        ull m = l+(r-l)/2;

        ull prev = 0;
        for_each(v,a) {
            ull temp = min(prev+v,m);
            prev = prev+v-temp;
        }

        if(prev != 0) l = m+1; 
        else r = m;
    }

    ull maxx = l;
    ull x = 0;

    for_each(v,a) {
        ull temp = min(x+v,maxx);
        x = x+v-temp;

        v = temp;
    }

    l = 0;
    r = maxx+1;

    while(l<r) {
        ull m = l+(r-l)/2;

        ull prev = 0;
        bool flag = 1;
        for_each(v,a) {
            if(prev+v < m) {
                flag = 0;
                break;
            }
            prev = prev+v - m;
        }

        if(flag) l = m+1;
        else r = m;
    }

    ull minn = l-1;
    // cout<<maxx<<" "<<minn<<" ";
    cout<<(maxx-minn);
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
