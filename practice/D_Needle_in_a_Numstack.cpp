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
    int n,k; cin>>n>>k;

    // int arr[n]; arr_in(arr);

    auto ask = [&](int i) -> int {
        int v;
        cout<<"? "<<i+1<<endl; cout.flush();
        cin>>v;
        return v;
        // return arr[i];
    };

    auto ans = [](int v) {
        cout<<"! "<<v<<endl; cout.flush();
    };

    auto ans2 = [](int v1, int v2) {
        cout<<"! "<<v1<<" "<<v2<<endl; cout.flush();
    };

    int a[k],b[k];

    int j = -1;
    rep(i,0,k-1) {
        int v1 = ask(i);
        int v2 = ask(n-k+i);

        a[i] = v1;
        b[(n-k+i)%k] = v2;
    }

    rep(i,0,k-1) if(a[i] != b[i]) {j = i;}

    if(j == -1) {
        if(n == 2*k) ans2(k,k);
        else ans(-1);
        return;
    }
    // cout<<"j "<<j<<endl;

    int l = 0;
    int r = ((n-1-j)/k) + 1;

    while(l<r) { // give first unsucessful
        int m = l + (r-l)/2;

        int v = ask(m*k+j);
        if(v == a[j]) l = m+1;
        else r = m;
    }

    int x = (l-1)*k+j; //last successful
    // cout<<"x "<<x<<endl;

    int c[k];
    rep(i,1,k-1) {
        int v = ask(x+i);
        c[i] = v;
    }

    l=x+1;
    while(l<x+k && c[l-x] == a[l%k]) l++;

    r=x+k-1;
    while(r>x && c[r-x] == b[r%k]) r--;
    // cout<<l<<" "<<r<<endl;
    l--, r++;
    // cout<<l<<" "<<r<<endl;
    l = min(l, n-k-1);
    r = max(r, k);

    if(l+1==r) ans2(l+1, n-l-1);
    else ans(-1);

    // assert(false);
}
int main()
{
    fastio;

    test
    {
        solve();
        // cout << endl;
    }

    return 0;
}
