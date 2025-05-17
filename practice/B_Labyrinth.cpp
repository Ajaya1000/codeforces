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
    int r,c; cin>>r>>c; r--,c--;
    int x,y; cin>>x>>y;

    vector<string> a(n); arr_in(a);
    vector<vector<int>> dist(n,vector<int>(m, INT_MAX));

    auto valid = [&n, &m, &a](int i, int j) {
        if(i<0 || i>=n || j<0 || j>=m) return false;

        // cout<<i<<" "<<j<<endl;
        return a[i][j] == '.';
    };

    deque<pii> q;
    q.push_front({r,c});
    dist[r][c] = 0;

    while (q.size())
    {
        auto [i,j] = q.front(); q.pop_front();

        if(valid(i-1,j) && dist[i-1][j] > dist[i][j]) {
            dist[i-1][j] = dist[i][j];
            q.push_front({i-1,j});
        }

        if(valid(i+1,j) && dist[i+1][j] > dist[i][j]) {
            dist[i+1][j] = dist[i][j];
            q.push_front({i+1,j});
        }

        if(valid(i,j-1) && dist[i][j-1] > dist[i][j]+1) {
            dist[i][j-1] = dist[i][j]+1;
            q.push_back({i,j-1});
        }

        if(valid(i,j+1) && dist[i][j+1] > dist[i][j]) {
            dist[i][j+1] = dist[i][j];
            q.push_front({i,j+1});
        }
    }

    int count = 0;
    rep(i,0,n-1) rep(j,0,m-1) {
        int L = dist[i][j];
        int R = L + j - c;
        if(L<=x && R<=y) count++;
    }

    cout<<endl;
    cout<<count;
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
