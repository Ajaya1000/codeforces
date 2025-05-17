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

void solve(int qt)
{
    ll n; cin>>n;
    
    // map<pair<ll,ll>, int> mp;

    auto query = [&](ll l, ll r) {
        // auto it = mp.find({l,r});
        // if(it != mp.end()) return it->second;

        cout<<"? "<<l<<" "<<r<<endl; cout.flush();  
        int v; cin>>v;
        return v;
    };

    auto printAns = [] (int k) {
        cout<<"! "<<k<<endl; cout.flush();
    };

    ll d = n/4;

    int v11 = query(1, d);
    int v12 = query(d + 1ll, 2ll*d);

    int v21 = query(2ll*d + 1ll, 3ll*d);
    // int v22 = query(3ll*d + 1ll, n);

    auto case1 = [&] (ll l, ll r) {
        while(l<r) {
            ll m = l + (r-l+1) / 2;
            int v = query(m, n);
            if(v) {
                r = m-1;
            } else {
                l = m;
            }
        }

        return l;
    };

    auto case2 = [&] (ll l, ll r) {
        ll x = l;
        while (l<r)
        {
            ll m = l + (r-l) / 2;
            int v = query(x, m);

            if(v) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return l;
    };

    auto case3 = [&] (ll l, ll r) {
        while (l<r) 
        {
            ll m = l + (r-l) / 2;
            int v = query(1, m);
            if(v == 0) {
                r = m;
            } else {
                l = m+1;
            }
        }
        
        return l;
    };

    if(v11 == 0 && v12 == 0) {
        int v1 = query(1, 2ll*d);
        if(v1 == 1) {
            printAns(case2(1, 2ll*d));
        } else {
            printAns(n - case1(1, 2ll*d) + 1ll);
        }
    } else if (v11 == 1 && v12 == 1) {
         printAns(case2(1, d));
    } else if(v21 == 0) {
         int v2 = query(2*d + 1, n);
         if(v2) {
            printAns(case2(2ll*d + 1ll, n) - 2ll*d);
         } else {
            printAns(case3(2ll*d+1, n));
         }
    } else if (v21 == 1) {
        printAns(case2(3ll*d + 1ll, n) - 3ll*d);
    } else {
        exit(5);
    }
}

int main()
{
    fastio;
    
    test
    {
        solve(t);
        // cout << endl;
    }

    return 0;
}
