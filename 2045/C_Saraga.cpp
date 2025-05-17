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
    string s[2]; arr_in(s);
    int a[2][26]; memset(a, -1, sizeof(a));

    repi(j, s[0].size()-1, 1) {  
        a[0][s[0][j]-'a'] = j;
    }

    int m = s[1].size();

    rep(i,0,m-2) {
        a[1][s[1][i] - 'a'] = i;
    }

    int minn = INT_MAX;
    int l,r;

    rep(i,0,25) {
        if(a[0][i] == -1 || a[1][i] == -1) continue;
        // cout<<i<<" ";
        int curr = a[0][i] + s[1].size() - a[1][i];

        if(curr < minn) {
           minn = curr;
            l = a[0][i];
            r = a[1][i];
        }
    }

    if(minn == INT_MAX) {
        cout<<-1;
        return;
    }

    string str = "";
    rep(i,0,l) {
        str.pb(s[0][i]);
    }

    rep(i,r+1,s[1].size()-1) {
        str.pb(s[1][i]);
    }

    cout<<str;
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
