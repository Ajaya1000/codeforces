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
string merge(string a, string b) {
    string c = b+"#"+a;
    int n = c.size();

    vector<int> p(n,0);

    int flag = 0;
    rep(i,1,n-1) {
        int j = p[i-1];
        while(j>0 && c[i] != c[j]) j = p[j-1];
        if(c[i] == c[j]) j++;
        p[i] = j;

        if(p[i]>=b.size()) flag = 1;
    }

    if(flag) return a;

    rep(j, p[n-1],(int)b.size() - 1) {
        a.pb(b[j]);
    }

    return a;
}

void solve()
{
    string s[3];
    arr_in(s);

    vector<int> v = {0,1,2};
    int minn = INT_MAX;

    do {
        auto a = merge(s[v[0]], s[v[1]]);
        auto b = merge(a, s[v[2]]);
        minn = min(minn,(int)b.size());
    } while (next_permutation(v.begin(), v.end()));
    
    cout<<minn;
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
