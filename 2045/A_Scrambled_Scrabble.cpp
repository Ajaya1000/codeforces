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

void solve()
{
    string s; cin>>s;

    int vow,con,y,n,g;
    vow=con=y=n=g=0;

    for_each(c,s) {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') vow++;
        else if(c == 'Y') y++;
        else if(c == 'N') n++;
        else if(c == 'G') g++;
        else con++;
    }

    int ng = min(n,g);
    con += n + g - (2 * ng);

    //word count
    int maxx = 0;
    repi(i,5000,0) {
        int a = 2*ng + con;
        int b = vow;
        int needy = max(0,(2*i)-a) + max(0,i-b);
        if(needy > y) continue;
        int lefty = y - needy;

        int ng_used = min(min(2*i, max(n,g)), min(min(n,g), lefty + max(0,a-2*i)));

       maxx = max(maxx, (3*i + ng_used));
    }

    cout<<maxx;
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
