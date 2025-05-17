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
    int n,m,x; cin>>n>>m>>x;
    
    string s[n]; arr_in(s);

    auto getVal = [&] (int i, int j) {
        return s[i][j] - '0';
    };

    auto getf = [&](int i1, int j1, int i2, int j2) {
        ll temp1 = getVal(i1,j1);
        ll temp2 = getVal(i2,j2);
        return _pow(temp1-temp2, (ll)x);
    };

    //check for vailid zero-cycle grid
    bool flag = 1;
    rep(i,0,n-2) {
        rep(j,0,m-2) {
            ll val = getf(i,j,i+1,j) + getf(i+1,j,i+1,j+1) + getf(i+1,j+1,i,j+1) + getf(i,j+1,i,j);
            if(val) {
                flag = 0;
                break;
            }
        }
    }

    vector<vector<ll>> d;

    if(flag) {
        //calc the d(u,s)
        // s= {0,0}
        d = vector<vector<ll>>(n,vector<ll>(m));
        // calc the column
        rep(i,1,n-1) {
            d[i][0] = d[i-1][0] + getf(i,0,i-1,0);
        }

        rep(i,0,n-1) {
            rep(j,1,m-1) {
                d[i][j] = d[i][j-1] + getf(i,j,i,j-1);
            }
        }
    }

    int q; cin>>q;

    while(q--) {
        int i1,j1,i2,j2;
        cin>>i1>>j1>>i2>>j2;
        i1--;j1--;i2--;j2--;

        if(!flag) {
            cout<<"INVALID";
        } else {
            cout<<d[i1][j1] - d[i2][j2];
        }
        
        cout<<endl;
    }
}
int main()
{
    fastio;

    // test
    {
        solve();
        // cout << endl;
    }

    return 0;
}
