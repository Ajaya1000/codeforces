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

struct comp {
    bool operator()(pii &a, pii &b) {
        return (a.second > b.second) || (a.second == b.second && a.first < b.first);
    }
};

void solve()
{
    int n;cin>>n;
    int a[n];
    arr_in(a);

    map<int,int> mp;
    for_each(v,a) mp[v]++;
    
    priority_queue<pii, vector<pii>, comp> pq;
    vector<int> vec;
    for_each(p, mp) {vec.pb(p.second); } //cout<<p.first<<" "<<p.second<<endl;

    int m = vec.size();
    vector<vector<int>> dp(m,vector<int>(m, INT_MAX));

    auto giveDP = [&](int i, int j) {
        if(i>=m) return 0;
        return dp[i][j];
    };

    repi(i,m-1,0) {
        rep(j,0,m-1) {
            dp[i][j] = min(dp[i][j], 1+giveDP(i+1,j+1));

            if(j >= vec[i])
            dp[i][j] = min(dp[i][j], giveDP(i+1,j-vec[i]));
        }
    }

    cout<<dp[0][0];

    // int count = 0;

    // int curr = 0;
    // rep(i,0,m-1) {
    //     if(vec[i].second <= curr) {
    //         curr -= vec[i].second;
    //     } else {
    //         curr++;
    //         count++;
    //     }
    // }

    // for_each(p, mp) {
    //      pq.push(p);
    //      vec.pb(p.first);
    //      cout<<p.first<<" "<<p.second<<endl;
    // }

    // int count = 0;
    // int lst = 0;
    // for_each(v,vec) {
    //     if(mp[v]>0) {
    //         count++;
    //         lst = v;
    //         cout<<"first "<<v<<endl;
    //     }

    //     while(!pq.empty() && (pq.top().first <= lst || pq.top().second <= 0)) pq.pop();

    //     if(!pq.empty()) {
    //         auto top = pq.top();pq.pop();
    //         cout<<"second "<<top.first<<" "<<top.second<<endl;
    //         mp[top.first]--;
    //         pq.push({top.first, top.second-1});
    //     }
    // }

    // cout<<count;
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
