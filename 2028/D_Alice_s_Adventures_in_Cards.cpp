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
    int a[3][n];

    arr_in(a[0]);arr_in(a[1]);arr_in(a[2]);

    vector<pii> path(n,{-1,-1});
    int minn[3] = {n-1,n-1,n-1};

    repi(i,n-2,0) {
        int k = -1;
        rep(j,0,2) if(a[j][i] > a[j][minn[j]]) k = j;
        if(k == -1) continue;
        path[i] = {k,minn[k]};
        rep(j,0,2) if(a[j][i] < a[j][minn[j]]) minn[j] = i;
    }

    if(path[0].second == -1) {
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;

    int i=0;

    vector<pii> ans;
    while(i<n-1) {
        ans.pb(path[i]);
        i = path[i].second;
    }

    cout<<ans.size()<<endl;
    string str="qkj";

    for_each(p,ans) cout<<str[p.first]<<" "<<p.second+1<<endl;
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
