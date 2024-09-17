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
    int n; cin>>n;
    ull w; cin>>w;

    vector<int> p(n+1, -1);
    rep(i,2,n) cin>>p[i];

    vector<int> dep(n+1),len(n+1), c1(n+1), c2(n+1);
    rep(i,2,n) dep[i] = dep[p[i]]+1;

    rep(i,1,n) {
        int x = i, y = (i%n)+1;

        while(x!=y) {
            if(dep[x] < dep[y]) swap(x,y);
            (c1[x]?c2[x]:c1[x]) = i;
            x = p[x];
            len[i]++;
        }
    }

    int x;
    ull y;

    ull rem = n;
    ull sum = 0;
    rep(i,1,n-1) {
        cin>>x>>y;
        sum+=y;
        if((--len[c1[x]]) == 0) rem--;
        if((--len[c2[x]]) == 0) rem--;

        ull res = sum*(ull)2 + rem * (w-sum);
        cout<<res<<" ";
    }
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
