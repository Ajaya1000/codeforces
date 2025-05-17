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
    int n,q; cin>>n>>q;

    vector<vector<int>> mat(n);
    rep(i,1,n-1) {
        int p; cin>>p; p--;
        mat[p].push_back(i);
    }

    int a[n]; arr_in(a);

    vector<int> t(n,INT_MAX);

    rep(i,0,n-1) {
        int temp = a[i];
        a[i] = 0;

        priority_queue<pii> pq;
        pq.push({a[0], 0});

        rep(j,0,n-1) {
            auto [_, u] = pq.top(); pq.pop();
            t[u] = min(t[u],j);

            for_each(v, mat[u]) {
                pq.push({a[v], v});
            }
        }

        a[i] = temp;
    }

    while(q--) {
        int u; cin>>u; u--;

        cout<<t[u]<<" ";
    }
}
int main()
{
    fastio;

    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}
