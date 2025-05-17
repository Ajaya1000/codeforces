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

    ll a[n], b[m];
    arr_in(a); arr_in(b);

    sort(a,a+n);
    sort(b,b+m);

    vector<ll> ap, bp;
    for(int i = 0; i<n-i-1;i++) {
        ll pre = (i > 0)?ap[i-1]:0;
        ap.pb(pre+a[n-i-1]-a[i]);
    }

    for(int i = 0; i<m-i-1;i++) {
        ll pre = (i > 0)?bp[i-1]:0;
        bp.pb(pre+b[m-i-1]-b[i]);
    }

    // for_each(v,ap) cout<<v<<" "; cout<<endl;
    // for_each(v,bp) cout<<v<<" "; cout<<endl;

    vector<ll> ans;

    rep(k,1,(n+m) / 3) {
        auto val = [&](int x) -> ll {
            ll sum = 0;
            if(x > 0) sum += ap[x-1];
            if(k-x > 0) sum += bp[k-x-1];
            return sum;
        };

        int l = max(0, 2*k-m);
        int r = min(k, n - k);

        // cout<<l<<" "<<r<<endl;

        if(l > r) break;
        while(l < r) {
            if(r-l < 3) {
                ll maxx = 0;
                int maxl = l;
                rep(x,l,r) {
                    if(val(x) > maxx) {
                        maxx = val(x);
                        maxl = x;
                    }
                }

                r = l = maxl;
                break;
            }

            int m1 = l + (r-l) / 3;
            int m2 = r - (r-l) / 3;

            if(val(m1) >= val(m2)) {
                r = m2;
            } else {
                l = m1;
            }
        }

        ans.pb(val(l));
    }

    cout<<ans.size()<<endl;
    for_each(v,ans) cout<<v<<" ";
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
