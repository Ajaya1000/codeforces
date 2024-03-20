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

const int N = 2e5;
void solve()
{
    int n,m;cin>>n>>m;

    vector<set<int>> temp(n);

    int u,v,c;
    rep(i,0,m-1) {
        cin>>u>>v>>c;
        u--,v--,c--;
        temp[u].insert(c);
        temp[v].insert(c);
    }

    u_map<int, vector<pii>> edge;

    int b,e;cin>>b>>e;
    b--,e--;

    if(b==e) {
        cout<<0;
        return;
    }

    int curr=N+1;
    rep(i,0,n-1) {
        auto s = temp[i];
        int w = 1 - (i == b || i == e);
        for_each(v,s) {
            edge[curr].pb({v,w});
            edge[v].pb({curr,0});
        }
        curr++;
    }

    int l = *temp[b].begin();
    int r = *temp[e].begin();
    
    u_map<int,int> dist;
    
    deque<int> q;

    dist[l] = 0;

    q.push_front(l);

    while(q.size()) {
        int u = q.front();q.pop_front();

        for_each(p,edge[u]) {
            int v = p.first;
            int w = p.second;

            // if(v == r) break;
            auto it = dist.find(p.first);
            int d;
            if(it == dist.end()) {
                d = INT_MAX;
            } else {
                d = it->second;
            }

            if(d > dist[u] + w) {
                dist[v] = dist[u] + w;

                if(w) q.push_back(v);
                else q.push_front(v);
            }
         }
    }

    cout<<dist[r]+1;
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