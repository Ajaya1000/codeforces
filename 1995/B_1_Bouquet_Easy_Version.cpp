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
    int n;cin>>n;
    ull m;cin>>m;

    ull a[n];
    arr_in(a);
    
    map<ull,int> mp;
    for_each(v,a) mp[v]++;

    vector<pair<ull,int>> vec;
    for_each(p,mp) vec.push_back(p);

    ull maxx = 0;

    auto maxUse = [](ull m, pair<ull,int> p)-> vector<ull> {
        ull d = m/p.first;
        ull maxAvailable = (ull)p.second;
        ull minn = min(d, maxAvailable);
        ull used = p.first * minn;

        return {used, minn};
    };

    rep(i,0,vec.size()-1) {
        maxx = max(maxx, maxUse(m, vec[i])[0]);

        if(i>0 && vec[i-1].first+(ull)1 == vec[i].first) {
           auto use = maxUse(m, {vec[i].first+vec[i-1].first, (ull)min(vec[i-1].second, vec[i].second)});
           maxx = max(maxx, use[0] + maxUse(m-use[0],{vec[i].first, vec[i].second - use[1]})[0]);
           maxx = max(maxx, use[0] + maxUse(m-use[0],{vec[i-1].first, vec[i-1].second - use[1]})[0]);
        }
    }

    cout<<maxx;
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
