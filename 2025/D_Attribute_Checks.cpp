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
    int n,m; cin>>n>>m;

    int v;
    vector<array<vector<int>,2>> checks;

    rep(i,0,n-1) {
        cin>>v;
        if(v==0) {
            checks.pb(array<vector<int>,2>());
        } else if(!checks.empty()) {
            if(v>0) checks[checks.size()-1][0].pb(v);
            else if(v<0) checks[checks.size()-1][1].pb(abs(v));
        }
    }

    for_each(p_vec, checks) {
        for_each(vec, p_vec) {
            sort(vec.begin(),vec.end());
        }
    }

    assert(checks.size()==m);

    vector<int> dp(m+1);

    repi(i,m-1,0) {
        vector<int> curr(m+1);

        auto getValidChecks = [&checks, &i, &dp](int p) {
            int q = i+1 - p;

            int count1 = distance(checks[i][0].begin(), upper_bound(checks[i][0].begin(), checks[i][0].end(), p));
            int count2 = distance(checks[i][1].begin(), upper_bound(checks[i][1].begin(), checks[i][1].end(), q));
            int count = count1+count2;

            return dp[p] + count;
        };

        rep(j,0,m-1) {
            curr[j] = max(getValidChecks(j), getValidChecks(j+1));
        }

        dp=curr;
    }

    cout<<dp[0];
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
