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
    int n,q;cin>>n>>q;
    int col[n+1];
    col[0] = 0;
    rep(i,1,n) cin>>col[i];

    vector<vector<int>> mat(n+1);
 
    rep(i,1,n-1) {
        int u,v;
        cin>>u>>v;
        mat[u].pb(v);
        mat[v].pb(u);
    }
    
    int tot,two,more,twp,x;
    tot = two = more = twp = x = 0;

    vector<int> parent(n+1);
    vector<int> num(n+1);

    function<void(int,int)> dfs = [&](int p, int u) {
        int sumc = 0;
        parent[u] = p;

        for_each(v, mat[u]) {
            if(v==p) continue;

            if(col[v] == 1) sumc++;
            dfs(u,v);
        } 

        if(col[p] == 0 && col[u] == 1) twp++;

        if(col[u] == 1) {
             tot++;
            if(sumc == 2) {
                // cout<<"x changes to "<<x<<endl;
                two++, x^=u;
            }
            if(sumc > 2) more++;
        }

        num[u] = sumc;
    };

    function<void(int)> flip = [&](int u) {
        col[u]^=1;
        int d = (col[u] == 1 ? 1 : -1);
        tot += d;

        twp -= d*num[u];
        if(col[parent[u]] == 0) twp+=d;
        // cout<<"-----------------Flipping--------------------------\n";
        // cout<<"u is "<<u<<endl;
        // cout<<"parent "<<parent[u]<<endl;
        // cout<<"color "<<col[parent[u]]<<endl;

        if(num[u] == 2) two+=d, x^=u;
        if(num[u] > 2) more+=d;

        bool flag = (col[parent[u]] == 1);


        if(flag && num[parent[u]] == 2) two--, x^=parent[u];
        if(flag && num[parent[u]] > 2) more--;

        num[parent[u]] += d;

        if(flag && num[parent[u]] == 2) two++, x^=parent[u];
        if(flag && num[parent[u]] > 2) more++;

        // cout<<"x flips to "<<x<<endl;
    };

    auto check = [&] () {
        // cout<<"----------------Checking---------------------------\n";
        // cout<<"tot: "<<tot<<endl;
        // cout<<"more & two: "<<more<<" "<<two<<endl;
        // cout<<"twp "<<twp<<endl;
        // cout<<"x is "<<x<<endl;

        if(!tot)return false;
        if(more||two>1)return false;
        if(twp>1)return false;
        if(two && col[parent[x]]==1) return false;
        return true;
    };

    dfs(0,1);

    // cout<<"-----------------Before-------------------------\n";
    // cout<<"tot: "<<tot<<endl;
    // cout<<"more & two: "<<more<<" "<<two<<endl;
    // cout<<"twp "<<twp<<endl;
    // cout<<"x is "<<x<<endl;

    rep(i,1,q) {
        int u;cin>>u;
        flip(u);
        if(check()) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main()
{
    fastio;

    test
    {
        solve();
        // cout << endl;
    }

    return 0;
}
