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
const int N=1e4+5;
void solve()
{
    int m; cin>>m;
    vector<int> s(m); arr_in(s);

    sort(s.begin(),s.end());

    vector<int> dp(N,-1);

    function<int(int)> getValue = [&] (int u) -> int {
        if(dp[u] != -1) return dp[u];

        set<int> values;

        for_each(v,s) {
            if(v>u) break;
            values.insert(getValue(u-v));
        }

        int i=0;
        for(auto it = values.begin(); it != values.end(); it++, i++) {
            if(*it != i) break;
        }

        return dp[u] = i;
     };

    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        int a[n]; arr_in(a);

        int x = 0;
        for_each(v,a) x ^= getValue(v);
        if(x) cout<<"W";
        else cout<<"L";
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
