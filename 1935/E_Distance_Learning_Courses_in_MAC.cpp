// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
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
    ll a[n],b[n];
    rep(i,0,n-1) cin>>a[i]>>b[i];

    int dp1[n][31],dp2[n][31];

    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));

    rep(j,0,n-1){
        bool f = 0;
        ll p = 1ll<<30;
        repi(i,30,0) {
            if(j>0) {
                dp1[j][i] = dp1[j-1][i];
                dp2[j][i] = dp2[j-1][i];
            }
            
            if(b[j]&p) {
                dp1[j][i]++;
                if((a[j]&p) == 0) f = 1;
                dp2[j][i]+=f;
            }

            p = p>>1;
        }
    }

    // repi(i,4,0) {
    
    //     cout<<dp1[n-1][i]<<" ";
    // }
    // cout<<endl;

    // repi(i,4,0) {
    
    //     cout<<dp2[n-1][i]<<" ";
    // }
    // cout<<endl;


    int q;cin>>q;
    int l,r;
    while(q--) {
        cin>>l>>r;
        l--,r--;
        bool f = 0;

        ll ans = 0;
        int x,y;
        repi(i,30,0) {
            ans = (ans<<1);

            if(f) {
                // cout<<"f"<<" ";
                ans += 1ll;
                continue;
            }

            x = dp1[r][i];
            y = dp2[r][i];

            if(l>0) {
                x -= dp1[l-1][i];
                y -= dp2[l-1][i];
            }
            
            if(x) ans += 1ll;

            if(x>1 && y>0) f = 1;

            // cout<<f<<" ";
        }
        // cout<<endl;
        cout<<ans<<" ";
    }
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