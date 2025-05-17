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
pii getIntersection(pii a, pii b) {
    return {max(a.first,b.first), min(a.second, b.second)};
}
void solve()
{
    int n; cin>>n;
    int a[n]; arr_in(a);

    vector<int> pre(n);
    pre[0]=a[0];
    rep(i,1,n-1) pre[i]=min(pre[i-1],a[i]);

    vector<int> suf(n);
    suf[n-1]=a[n-1];
    repi(i,n-2,0) suf[i] = min(suf[i+1],a[i]);

    int l,r;
    l = 0;
    r = n-1;

    pii ans={0,n-1};
    repi(i,n,1) {
        while(pre[l]>i) l++;
        while(suf[r]>i) r--;

        if(l>r) break;

        if(r-l+1>i) {
            cout<<0;
            return;
        }
        cout<<l<<" "<<r<<"\t";
        cout<<r-i+1<<" "<<l+i-1<<endl;
        ans = getIntersection(ans,{r-i+1,l+i-1});
    }

    cout<<(ans.second-ans.first+1);
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
