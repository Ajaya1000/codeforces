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
    int n,m; cin>>n>>m;
    vector<string> a(n); arr_in(a);

    vector<vector<int>> d(n,vector<int>(m, INT_MAX));
    deque<pii> q;
    q.push_back({0,0});
    d[0][0] = 0;

    auto valid = [&] (int i, int j) {
        if(i<0 || i>=n || j<0 || j >=m) return false;
        return true;
    };


    while (q.size())
    {
        auto [i0,j0] = q.front(); q.pop_front();

        auto handle = [&] (int dx, int dy) {
            int i1 = i0+dx;
            int j1 = j0+dy;
            if(!valid(i1,j1)) return;

            if(a[i1][j1] == a[i0][j0]) {
                if(d[i1][j1] > d[i0][j0]) {
                    d[i1][j1] = d[i0][j0];
                    q.push_front({i1,j1});
                }
            } else {
                if(d[i1][j1] > d[i0][j0]+1) {
                    d[i1][j1] = d[i0][j0]+1;
                    q.push_back({i1,j1});
                }
            }
        };

        handle(0,-1);
        handle(0,1);
        handle(1,0);
        handle(-1,0);
    }

    cout<<d[n-1][m-1];
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
