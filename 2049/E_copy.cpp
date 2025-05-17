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
    
    // ll n; cin>>n;
    ll n, p, k; cin>>n>>p>>k;
    
    int tot = 0;
    // map<pair<ll,ll>, int> mp;
    auto query = [&](ll l, ll r) {
        // auto it = mp.find({l,r});
        // if(it != mp.end()) return it->second;
        tot++;
        if(tot > 33) {
            cout<<"max query reached for "<<qt+1<<endl;
        }
        
        // cout<<"? "<<l<<" "<<r<<endl; //cout.flush();  

        // int v; cin>>v;
        int v = 0;
        if(l<=p && p<=r) v++;
        if(r-l+1 >= k) v = 1-v;

        // mp[{l,r}] = v;
        return v;
    };

    auto printAns = [&] (int ki) {
        // cout<<"! "<<k<<endl; cout.flush();
        // cout<<ki;
        if(ki != k) {
            cout<<"failed for "<<qt+1<<endl;
        }
    };

    ll d = n/4;

    int v11 = query(1, d);
    int v12 = query(d + 1ll, 2ll*d);

    // int v22 = query(3ll*d + 1ll, n);

    auto case1 = [&] (ll l, ll r) {
        // cout<<"func 1: "<<l<<" "<<r<<endl;
        // if(qt > 10) {
        //     exit(101);
        // }

        while(l<r) {
            ll m = l + (r-l+1) / 2;
            int v = query(m, n);
            if(v) {
                r = m-1;
            } else {
                l = m;
            }
        }

        return l; // where 0 starts from right
    };

    auto case2 = [&] (ll l, ll r) {
        // cout<<"func 2: "<<l<<" "<<r<<endl;
        // if(qt > 10) {
        //     exit(102);
        // }
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
        
        return l; // where 0 ends from left
    };

    auto case3 = [&] (ll l, ll r) {
        // cout<<"func 3: "<<l<<" "<<r<<endl;
        // if(qt > 10) {
        //     exit(103);
        // }
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
        
        return l; // where 0 starts from left
    };

    if(v11 == 0 && v12 == 0) {
        int v1 = query(1, 2ll*d);
        if(v1 == 1) {
            // k <= 2d
            // search from 1 to 2d form: 0 0 0 1 1 1 (from left)
            cout<<"case 1"<<endl;
            printAns(case2(1, 2ll*d));
        } else {
            // k > 2d
            // search from 1 to 2d with suffix n
            // form : 0 0 0 1 1 1 (from right)
            cout<<"case 2"<<endl; 
            printAns(n - case1(1, 2ll*d) + 1ll);
        }
    } else if (v11 == 1 && v12 == 1) {
        // case2();
        
        // k <= d
        // will follow 0 0 0 1 1 1 (from left)
        // search 0 - d
        cout<<"case 3"<<endl; 
         printAns(case2(1, d));
    } else { 
        int v21 = query(2ll*d + 1ll, 3ll*d);
        if(v21 == 0) {
            // case3();
            int v2 = query(2*d + 1, n);
            if(v2) {
                // k <= 2d
                cout<<"case 4"<<endl; 
                printAns(case2(2ll*d + 1ll, n) - 2ll*d);
            } else {
                // k > 2d
                // form:  1 1 1 1 1 1 0 0 0 0 0 (from left)
                cout<<"case 5"<<endl; 
                printAns(case3(2ll*d+1, n));
            }
        } else if (v21 == 1) {
            // case4();
            // k <= d
            // will follow 0 0 0 1 1 1 (from left)
            // search 3d + 1 - n
            cout<<"case 6"<<endl;
            printAns(case2(3ll*d + 1ll, n) - 3ll*d);
        } 
    }
}

int main()
{
    fastio;
    
    test
    {
        solve(t);
        cout << endl;
    }

    return 0;
}
