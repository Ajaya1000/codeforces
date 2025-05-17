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
    vector<string> s(n); arr_in(s);

    auto canMove = [&](int i, int j) -> bool {
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        return (s[i][j] == '#');
    };

    vector<vector<int>> in(n, vector<int>(m)),low(n, vector<int>(m)), visited(n, vector<int>(m));


    int timer = 0;
    bool hasArt = 0;
    function<void(int,int,int,int)> dfs = [&](int i, int j, int i0, int j0) {
        visited[i][j] = 1;
        in[i][j] = low[i][j] = ++timer;
        int child = 0;

        vector<pii> dir = {{-1,0},{1,0}, {0,-1}, {0,1}};
        for(auto &[x,y]: dir){
            if(x==y) continue;
            int i1 = i+x;
            int j1 = j+y;

            if(!canMove(i1,j1)) continue;
            if(i1 == i0 && j1==j0) continue;

            if(visited[i1][j1]) {
                low[i][j] = min(low[i][j] , in[i1][j1]);
            } else {
                dfs(i1,j1,i,j);
                low[i][j] = min(low[i][j] , low[i1][j1]);
                child++;
                if(i0 == -1 && j0 == -1) continue;
                if(low[i1][j1] >= in[i][j]) {
                    // cout<<i1<<" "<<j1<<" "<<low[i1][j1]<<" "<<i<<" "<<j<<" "<<in[i][j]<<endl;
                    hasArt = 1;
                }
            }
        }

        if(i0 == -1 && j0 == -1 && child > 1) {
            hasArt = 1;
        }
    };

    int count = 0;
    int tot = 0;
    rep(i,0,n-1) {
        rep(j,0,m-1) {
            if(!canMove(i,j)) continue;
            tot++;
            if(visited[i][j]) continue;
            dfs(i,j,-1,-1);
            count++;
        }
    }

    if(tot < 2) cout<<-1;
    else if(count > 1) {
        cout<<0;
    } else if(hasArt) {
        cout<<1;
    } else if(tot == 2) {
        cout<<-1;
    } else {
        cout<<2;
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
