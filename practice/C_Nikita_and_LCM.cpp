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
    vector<ull> a(n);
    ull maxx = 0;

    set<ull> s;
    for_each(v,a) {
        cin>>v;
        s.insert(v);
        maxx = max(maxx,v);
    }

    for_each(v,a) {
        if(maxx%v) {
            cout<<n;
            return;
        }
    }

    auto getMaxxValue = [&](ull p) {
        ull l = 1;

        int count = 0;
        for_each(v,a) {
            if(p%v) continue;
            l = lcm(l,v);
            count++;
        }

        if(l == p) return count;
        return 0;
    };

    int ans = 0;
    for(ull j=1;j*j<=maxx;j++) {
        if(maxx % j) continue;

        if(s.find(j) == s.end()) {
            ans = max(ans,getMaxxValue(j));
        }

        if(s.find(maxx/j) == s.end()) {
            ans = max(ans,getMaxxValue(maxx/j));
        }
    }

    cout<<ans;
    
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
