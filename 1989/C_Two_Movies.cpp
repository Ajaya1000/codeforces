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
    int n;cin>>n;

    int a[n],b[n];
    arr_in(a);
    arr_in(b);

    int x1,x2,y,z;
    x1=x2=y=z=0;

    rep(i,0,n-1) {
        if(a[i] == b[i]) {
            if(a[i] == 1) x1++;
            else if(a[i] == -1) x2++;
        } else {
            if(a[i] == 1) y++;
            else if(b[i] == 1) z++; 
        }
    }

    int temp;
    // add x1
    if(y > z) {
        temp = min(y-z, x1);
        z+=temp;
        x1-=temp;
    } else if( z > y) {
        temp = min(z-y, x1);
        y+=temp;
        x1-=temp;
    }

    if(x1) {
        temp = x1/2;
        y += temp;
        z += (x1 - temp);
    }

    if(y > z) {
        temp = min(y-z, x2);
        y-=temp;
        x2-=temp;
    } else if(z > y) {
        temp = min(z-y,x2);
        z-=temp;
        x2-=temp;
    }

    if(x2) {
        temp = x2/2;
        y -= temp;
        z -= (x2 - temp);
    }

    cout<<min(y,z);
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
