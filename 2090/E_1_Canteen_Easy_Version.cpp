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
    int n,k; cin>>n>>k;
    vector<vector<int>> a(2,vector<int>(n)); 
    for_each(v,a) arr_in(v);

    vector<int> sa,sb;

    int maxx = 0;

    rep(i,0,n-1) {
        sa.push_back(i);

        while(a[1][i] > 0 && sa.size()) {
            if(a[1][i] < a[0][sa.back()]) {
                a[0][sa.back()] -= a[1][i];
                a[1][i] = 0;
            } else {
                a[1][i] -=  a[0][sa.back()];
                a[0][sa.back()] = 0;
                maxx = max(maxx, i - sa.back() + 1);
                sa.pop_back();
            }
        }

        if(a[1][i] > 0) sb.push_back(i);
    }

    for(int j=0;j<sb.size();j++) {
        int i = sb[j];

        while(a[1][i] > 0 && sa.size()) {
            if(a[1][i] < a[0][sa.back()]) {
                a[0][sa.back()] -= a[1][i];
                a[1][i] = 0;
            } else {
                a[1][i] -=  a[0][sa.back()];
                a[0][sa.back()] = 0;
                maxx = max(maxx, i + n - sa.back() + 1);
                sa.pop_back();
            }
        }
    }
    assert(sa.empty());
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
