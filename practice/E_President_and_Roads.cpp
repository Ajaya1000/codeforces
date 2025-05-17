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
#define pli pair<ll, int>
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

void distance(int x, int s, vector<vector<ll>> &dist, vector<vector<pii>> &g, vector<vector<int>> &edges) {

    priority_queue<pli, vector<pli>, greater<pli>> minn;

    minn.push({0,s});
    dist[s][x] = 0;

    while(minn.size()) {
        auto [d,u] = minn.top(); minn.pop();

        for(auto &[i,v]: g[u]) {
            ll w = edges[i][2];
            if(dist[v][x] > d+w) {
                dist[v][x] = d+w;
                minn.push({dist[v][x],v});
            }
        }
    }
}

void solve()
{
    int n,m,s,t; cin>>n>>m>>s>>t; s--,t--;
    vector<vector<pii>> g(n),gt(n);
    vector<vector<int>> edges;

    rep(i,0,m-1) {
        int u,v,w; cin>>u>>v>>w; u--,v--;
        g[u].pb({i,v});
        gt[v].pb({i,u});

        edges.pb({u,v,w});
    }

    vector<vector<ll>> dist(n,vector<ll>(2, LLONG_MAX));
    distance(0,s,dist,g,edges);
    distance(1,t,dist,gt,edges);

    ll min_d = dist[t][0];

    set<pli> minn;
    minn.insert({0,s});

    vector<bool> req(m,0);

    while(minn.size()) {
        auto [d,u] = *minn.begin(); minn.erase(minn.begin());
        bool flag = minn.empty();
        // if(u==4) {
        //     cout<<" u = 4 "<<d<<" "<<minn.top().first<<" "<<minn.top().second<<endl;
        // }
        int count = 0;
        int rp;
        for(auto &[i,v]: g[u]) {
            ll w = edges[i][2];
            if(dist[u][0] != LLONG_MAX && dist[v][1] != LLONG_MAX && dist[u][0] + dist[v][1] + w == min_d) {
                count++;
                minn.insert({dist[u][0]+w, v});
                // cout<<dist[u][0]+w<<" "<<u<<" "<<v<<endl;
                if(count == 1) {
                    rp = i;
                }
            }
        }

        if(flag && count == 1) {
            req[rp] = 1;
        }
    }
    
    rep(i,0,m-1) {
        int u = edges[i][0];
        int v = edges[i][1];
        ll w = edges[i][2];

        if(req[i]) {
            cout<<"YES"<<endl;
            continue;
        }

        // int temp = min_d - dist[u][0] - dist[v][1] - 1;
        // cout<<"temp "<<temp<<" ";
        if( dist[u][0] != LLONG_MAX && dist[v][1] != LLONG_MAX &&  (min_d - dist[u][0] - dist[v][1] - 1) > 0) {
            cout<<"CAN "<<w-(min_d - dist[u][0] - dist[v][1] - 1)<<endl;
        } else {
            cout<<"NO"<<endl;;
        }
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
