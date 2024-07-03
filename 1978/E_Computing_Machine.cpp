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

    string a,b;
    cin>>a>>b;

    rep(i,1,n-2) {
        if(b[i] == '1') continue;
        if(a[i-1] == '0' && a[i+1] == '0') b[i] = '2';
    }

    rep(i,1,n-2) {
        if(a[i] == '1') continue;
        if(b[i-1] != '0' && b[i+1] != '0') a[i] = '2';
    }

    // cout<<a<<endl<<b<<endl;

    int pre[n];
    memset(pre,0,sizeof(pre));

    int count = 0;
    rep(i,0,n-1) {
        if(a[i] != '0') count++;
        pre[i] = count;
    }

    auto givePre = [&] (int i) {
        if(i >= 0 && i<n) return pre[i];
        return 0;
    };

    int q;cin>>q;
    int l,r;
    while(q--) {
        cin>>l>>r;
        l--,r--;

        if(l == r) {
            cout<<((int)(a[l] == '1'));
        } else if(l+1 == r) {
            cout<<((int)(a[l] == '1') + (int)(a[r] == '1'));
        } else if(l+2 == r) {
            int val = givePre(r) - givePre(l-1);
            if(a[l] == '2') val--;
            if(a[r] == '2') val--;

            if(a[l+1] == '2' && (b[l] == '2' || b[r] == '2')) val--;
            cout<<val;
        } else {
            int val = givePre(r) - givePre(l-1);
            if(a[l] == '2') val--;
            if(a[r] == '2') val--;

            if(a[l+1] == '2' && b[l] == '2') val--;
            if(a[r-1] == '2' && b[r] == '2') val--;
            cout<<val;
        }

        cout<<endl;
    }
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
