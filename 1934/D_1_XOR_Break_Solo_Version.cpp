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
#define B 64
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
    ull n,m;cin>>n>>m;

    bitset<B> a(n),b(m);

    int x1,x2,y;
    x1 = x2 = y = -1;
    repi(i,63,0) {
        if(a[i] == 1) {
            if(x1 < 0) x1 = i;
            else if(x2<0) x2 = i;
        }

        if(b[i] == 1 && y < 0) y = i;
    }

    if(x2<0 || (x1>y && y>x2)) {
        cout<<-1;
    } else if(x1 == y || x2 == y) {
        cout<<1<<endl;
        cout<<n<<" "<<m;
    } else {
        cout<<2<<endl;
        b[x1] = 1;
        cout<<n<<" "<<b.to_ullong()<<" "<<m;
    }

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