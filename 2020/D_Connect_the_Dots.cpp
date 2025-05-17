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
const int D = 10;

void solve()
{
    int n,m; cin>>n>>m;
    int a,d,k;
    map<int, vector<pii>> mp;
    rep(i,0,m-1) {
        cin>>a>>d>>k;
        mp[a].pb({d,k});
    }

    vector<int> p(n+1,-1);

    vector<vector<pii>> dp(D+1, vector<pii>(D+1,{-1,-1}));

    function<int(int)> giveParent = [&p, &giveParent](int i) {
        if(p[i]==-1) return i;
        return p[i]= giveParent(p[i]);
    };

    auto unionPar = [&](int i, int j) {
        int u = giveParent(i);
        int v = giveParent(j);
        if(u==v) return;
        
        p[u] = v;
    };

    rep(i,1,n) {
        rep(j,1,D) {
            auto curr = dp[j][i%j];
            if(curr.second < i) continue;
            unionPar(curr.first, i);
        }

        for_each(curr_p, mp[i]) {
            auto curr_temp = dp[curr_p.first][i%curr_p.first];
            dp[curr_p.first][i%curr_p.first] = {max(i,curr_temp.first), max(i+curr_p.first*curr_p.second, curr_temp.second)};
        }
    }

    set<int> s;
    rep(i,1,n) {
        s.insert(giveParent(i));
    }

    cout<<s.size();
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
