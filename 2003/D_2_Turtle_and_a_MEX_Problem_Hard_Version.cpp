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
    int m;cin>>m;

    int maxx = -1;
    u_map<int,vector<int>> mp;

    int maxxu = -1, maxxv = -1;

    rep(i,0,n-1) {
        int l;
        cin>>l;

        vector<bool> a(l+2,false);

        rep(_,0,l-1) {
            int j; cin>>j;
            if(j>=0 && j<l+2) a[j] = 1;
        }

        int count = 0;
        vector<int> vecX;

        rep(z,0,l+1) {
            if(!a[z]) vecX.pb(z);

            if(vecX.size()==2) break;
        }
        

        mp[vecX[0]].pb(vecX[1]);
        maxxu = max(maxxu, vecX[0]);
        maxxv = max(maxxv, vecX[1]);
    }
    
    int dp[maxxv+1];
    memset(dp, -1, sizeof(dp));

    int maxValue = maxxu;

    repi(u,maxxv,0) {
        dp[u] = u;
        for_each(v,mp[u]) {
            dp[u] = max(dp[u], dp[v]);
        }

        if(mp[u].size()>1) maxValue = max(maxValue, dp[u]);
    }
   
    ull extra = 0;
    rep(i,0,min(m,maxxv)) {
        dp[i] = max(dp[i], max(i,maxValue));
        
        extra += (ull)(dp[i]-i);
    }

    ull ans = (ull)m*(ull)(m+1);
    ans/=(ull)2;

    cout<<(ans+extra);
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
