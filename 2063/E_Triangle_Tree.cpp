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
    int n; cin>>n; 
    vector<vector<int>> mat(n);

    rep(i,1,n-1) {
        int u,v;
        cin>>u>>v; u--,v--;
        mat[u].pb(v);
        mat[v].pb(u);
    }

    ll sum1 = 0;
    ll sum2 = 0;

    vector<int> s(n);
    vector<int> d(n);

    vector<ll> pre(n);

    function<int(int,int)> dfs = [&](int u, int p) -> int {
        s[u] = 1;
        pre[d[u]]++;

        for_each(v, mat[u]) {
            if(v==p) continue;
            // setting up the depth first
            d[v] = d[u] + 1;
            s[u] += dfs(v,u);
        }

        ll tot = 0;
        for_each(v, mat[u]) {
            if(v==p) continue;
            tot += (ll)s[v] * (ll)(s[u] - 1 - s[v]);
        }

        sum1 += tot * (ll)(2ll*d[u] + 1ll);
        
        return s[u];
    };

    d[0] = 0;
    dfs(0,-1);

    // cout<<sum1<<" ";
    sum1/=2; // dividing 2 for double count

    rep(i,1,n-1) {
        // cout<<pre[i]<<" ";
        sum2 -= pre[i]*(pre[i]-1)*(ll)i;
    }
    
    repi(i,n-2,0) pre[i] += pre[i+1];

    function<void(int,int)> dfs2 = [&](int u, int p) {
        sum2 += (ll)d[u] * (ll)(pre[d[u]] - s[u]) * 2ll;
        for_each(v, mat[u]) {
            if(v==p) continue;
            dfs2(v,u);
        }
    };

    dfs2(0,-1);

    // cout<<endl;
    // cout<<endl;
    // cout<<sum2<<" ";

    cout<<(sum2-sum1);
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
