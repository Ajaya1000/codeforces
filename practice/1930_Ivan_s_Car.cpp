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
    vector<vector<pii>> mat(n);
    rep(i,0,m-1) {
        int u,v; cin>>u>>v; u--,v--;
        mat[u].pb({v, 0});
        mat[v].pb({u, 1});
    }

    int s,t; cin>>s>>t; s--,t--;

    vector<vector<int>> dist(n, vector<int>(2,INT_MAX));

    deque<pii> q;

    q.push_back({s,0});
    q.push_back({s,1});

    dist[s][0] = 0;
    dist[s][1] = 0;

    while(!q.empty()) {
        auto [u,l] = q.front(); q.pop_front();

        for(auto &[v, r]: mat[u]) {
            if(l != r) {
                if(dist[v][r] > 1+dist[u][l]) {
                    dist[v][r] = 1+dist[u][l];
                    q.push_back({v,r});
                }
            } else {
                if(dist[v][r] > dist[u][l]) {
                    dist[v][r] = dist[u][l];
                    q.push_front({v,r});
                }
            }
        }
    }

    cout<<min(dist[t][0], dist[t][1]);
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
