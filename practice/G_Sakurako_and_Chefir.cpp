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
    int n; cin>>n;
    vector<vector<int>> mat(n);

    rep(_,1,n-1) {
        int u,v;cin>>u>>v;
        u--,v--;

        mat[u].pb(v);
        mat[v].pb(u);
    }

    const int N = log2(n);

    vector<int> maxReach(n);
    vector<int> lev(n);
    vector<vector<int>> dp(n, vector<int>(N+1));
    vector<vector<int>> anc(n, vector<int>(N+1));

    function<void(int,int, int)> dfs = [&](int p, int u, int t) {
        lev[u] = t;
        anc[u][0] = p;

        int maxx1,maxx2;
        maxx1=maxx2=0;

        for_each(v,mat[u]) {
            if(v==p) continue;
            dfs(u,v,t+1);
            int currMax = 1+maxReach[v];

            if(currMax>=maxx1) {
                maxx2 = maxx1;
                maxx1 = currMax;
            } else if(currMax>=maxx2){
                 maxx2 = currMax;
            }
        }

        for_each(v,mat[u]) {
            if(v==p) continue;

            if(maxx1 == 1+maxReach[v]) dp[v][0] = 1+maxx2;
            else dp[v][0] = 1+maxx1;
        }

        maxReach[u] = maxx1;
    };

    dfs(0,0,0);

    rep(j,1,N) {
        rep(i,0,n-1) {
            dp[i][j] = max(dp[i][j-1], dp[anc[i][j-1]][j-1] + lev[i] - lev[anc[i][j-1]]);
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }

    
    // rep(i,0,n-1) {
    //     cout<<maxReach[i]<<"\t";
    //     rep(j,0,N) {
    //         cout<<dp[i][j]<<" ";
    //     }

    //     cout<<endl;
    // }



    int q;
    cin>>q;

    rep(i,0,q-1) {
        // cout<<"query "<<i; cout<<endl;
        int u,v,k;
        cin>>u>>k; u--; 

        v=u;
        int ans = maxReach[u];
        int d = 0;

        int temp = (int)log2(lev[u]);
        

        repi(j,N,0) {
            if(k & (1<<j)) {
                // cout<<j<<" "<<anc[u][j]<<" "<<d<<" "<<dp[u][j]<<"\t\t";
                ans = max(ans, dp[u][j]+lev[v] - lev[u]);
                u = anc[u][j];
                d+=(1<<j);
            }
        }

        cout<<ans<<" ";
        // cout<<endl;
    }
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
