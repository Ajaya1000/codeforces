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

int divup(int a, int b) {
    return (a+b-1) / b;
}

void solve()
{
    int n;cin>>n;

    int a[n];
    int maxx = 0;

    for_each(v,a){
         cin>>v;
         maxx= max(maxx,v);
    }

    ll c;

    ll ans[maxx+1];

    memset(ans,0,sizeof(ans));

    rep(i,0,n-1) {
        c = 0;
        if((i == 0) || a[i] > a[i-1]) c++;
        if((i < n-1) && a[i] < a[i+1]) c--;

        int r = a[i];
        ans[r]+=c;

        while (r>0)
        {
            int val = divup(a[i],r);
            int l = divup(a[i], val);

            ans[l-1] += c * val;
            ans[r] -= c * val;

            r=l-1;
        }
    }


    rep(i,1,maxx) {
        ans[i] += ans[i-1];
    }
    
    rep(i,0,maxx-1) cout<<ans[i]<<" ";

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
