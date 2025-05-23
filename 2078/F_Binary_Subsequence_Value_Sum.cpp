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

ll _powMod(ll n, ll m)
{
    if (m == 0)
        return 1;

    ll res = _powMod(n, m / 2);

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
    ll n,q; cin>>n>>q;

    string s; cin>>s;

    ll c = 0; 
    for_each(ch,s) if(ch=='0') c++;

    ll temp = _powMod(2, n-4+mod-1);

    while (q--)
    {
        int i; cin>>i; i--;

        if(s[i] == '0') {
            c-=1;
            s[i] = '1';
        } else {
            c+=1;
            s[i] = '0';
        }

        ll val = ((n*(n+1ll)) - (c * 4ll * n) + (c * c * 4ll) - 2ll) % mod;
        val = (val * temp) % mod;
        val = (mod+val) % mod;

        cout<<val<<endl;
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
