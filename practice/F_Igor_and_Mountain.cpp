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

#define mod 998244353

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
    int n,m,d; cin>>n>>m>>d;
    string s[n]; arr_in(s);

    vector<ll> dp(m,0);

    rep(i,0,n-1) {
        int l,r;
        l = 0;
        r = 1;

        ll curr = dp[l];
        vector<ll> dp0(m);
        rep(j,0,m-1) {
            if(s[i][j] == '#') {
                dp0[j] = 0;
                continue;
            }

            if(i==0) { 
                dp0[j] = 1;
                continue;
            }

            while(r<=j) {
                curr += dp[r];
                curr = curr % mod;
                r++;
            }

            while(r<m && _pow(r-j,2)+1 <= _pow(d,2)) {
                curr += dp[r];
                curr = curr % mod;
                r++;
            }

            while(l<=j && _pow(j-l,2)+1 > _pow(d,2)) {
                curr -= dp[l];
                curr = curr % mod;
                l++;
            }



            // cout<<j<<" "<<l<<" "<<r<<endl;

            dp0[j] = curr;
        }

        l = 0;
        r = 1;

        curr = dp0[l];
        rep(j,0,m-1) {
            if(s[i][j] == '#') { 
                dp[j] = 0;
                continue; 
            }

            while(r<=j) {
                curr += dp0[r];
                curr = curr % mod;
                r++;
            }

            while(r<m && _pow(r-j,2) <= _pow(d,2)) {
                curr += dp0[r];
                curr = curr % mod;
                r++;
            }

            while(l<=j && _pow(j-l,2) > _pow(d,2)) {
                curr -= dp0[l];
                curr = curr % mod;
                l++;
            }

            dp[j] = curr;
            // cout<<j<<" "<<l<<" "<<r<<endl;
        }

        // for_each(v,dp0) cout<<v<<" "; cout<<endl;
        // for_each(v,dp) cout<<v<<" "; cout<<endl;
        // cout<<endl;
    }

    ll ans = 0;
    rep(i,0,m-1)  ans = (ans + dp[i]) % mod;
    ans = (mod+ans) % mod;

    cout<<ans;
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
