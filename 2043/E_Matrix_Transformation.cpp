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
#define B 30
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
int bit(int k, int x) {
    return (x>>k) & 1;
}

bool check(int k, int n, int m, vector<vector<int>> &a, vector<vector<int>> &b) {
    vector<bool> required(n+m, false);
    
    vector<vector<int>> mat(n+m);

    rep(i,0,n-1) {
        rep(j,0,m-1) {
            int bit1 = bit(k,a[i][j]);
            int bit2 = bit(k,b[i][j]);

            // cout<<bit1<<" "<<bit2<<" || ";

            if(bit1 != bit2) {
                if(bit2 == 1) {
                    required[n+j] = 1;
                } else {
                    required[i] = 1;
                }
            }

            if(bit2 == 0) {
                mat[n+j].pb(i);
            } else {
                mat[i].pb(n+j);
            }
        }
        // cout<<endl;
    }

    vector<int> state(n+m, 0);

    function<bool(int)> hasLoop = [&](int u) -> bool {
        if(state[u] == 2) return true;
        if(state[u] == 1) return false;

        state[u] = 2;

        for_each(v, mat[u]) {
            if(hasLoop(v)) return true;
        }

        state[u] = 1;

        return false;
    };

    rep(i,0,n+m-1) {
        if(!required[i]) continue;
        if(hasLoop(i)) return false;
    }

    return true;
}

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m)), b(n,vector<int>(m));

    for_each(v,a) arr_in(v);
    for_each(v,b) arr_in(v);

    rep(i,0,B) {
        if(!check(i,n,m,a,b)) { cout<<"No"; return;}
    }

    cout<<"Yes";
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
