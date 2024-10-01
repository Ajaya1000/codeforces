// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio				   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);				  \
    cout.tie(0)
#define test  \
    int t;   \
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
bool comp(vector<int> &a, vector<int> &b) {
    return a[0]<b[0];
}

long solution(vector<vector<int>> center) {
    long count = 0;

    map<int, map<int,long>> mp;
    for(auto &p:center) {
        mp[p[0]][p[1]]++;
    }

    auto getValue = [&](int x, int y) {
        auto xp = mp.find(x);
        if(xp == mp.end()) return 0l;
        auto yp = xp->second.find(y);
        if(yp == xp->second.end()) return 0l;
        return yp->second;
    };

    for(auto &xp: mp) {
        int x = xp.first;
        for(auto &yp: xp.second) {
            int y = yp.first;
            if(yp.second<=0) continue;

            count += (yp.second * (yp.second-1)) / 2l;
            
            count += getValue(x,y-2) * yp.second;
            count += getValue(x,y-1) * yp.second;

            count += getValue(x-2,y-2) * yp.second;
            count += getValue(x-2,y-1) * yp.second;

            count += getValue(x-2,y+2) * yp.second;
            count += getValue(x-2,y+1) * yp.second;

            count += getValue(x-1,y-2) * yp.second;
            count += getValue(x-1,y-1) * yp.second;

            count += getValue(x-1,y+2) * yp.second;
            count += getValue(x-1,y+1) * yp.second;
        }
    }

    return count;
}

void solve()
{
    int n; cin>>n;
    vector<vector<int>> center;
    int x,y;

    for(int i=0;i<n;i++) {
        cin>>x>>y;
        center.pb({x,y});
    }

    cout<<solution(center);
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