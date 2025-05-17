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
    int n,m; cin>>n>>m;
    string s; cin>>s;
    vector<vector<ll>> a(n,vector<ll>(m));

    for_each(vec,a) arr_in(vec);

    int i,j; i = j = 0;

    rep(x,0,(int)s.size() - 1) {
        if(s[x] == 'D') {
            ll sum = 0;
            for(int k=0;k<m;k++) sum += a[i][k];
            a[i][j] = -sum;
            i++;
        } else {
            ll sum = 0;
            for(int k=0;k<n;k++) sum += a[k][j];
            a[i][j] = -sum;
            j++;
        }
    }

    ll sum = 0;
    for(int k=0;k<m;k++) sum += a[n-1][k];
    a[n-1][m-1] = -sum;

    for_each(vec,a) { for_each(v,vec) cout<<v<<" "; cout<<endl; }
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
