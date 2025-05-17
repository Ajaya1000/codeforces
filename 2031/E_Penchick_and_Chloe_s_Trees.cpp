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
const int N = 1e6+5;
vector<int> big(N);
void solve()
{
    int n; cin>>n;
    vector<vector<int>> mat(n);

    rep(v,1,n-1) {
        int u; cin>>u; u--;

        mat[u].pb(v);
    }

    vector<int> visited(n,0);
    rep(i,0,n) big[i] = -1;

    function<int(int)> dfs = [&](int u) -> int {
        if(visited[u]) exit(5);
        visited[u] = 1;
        
        int d = 0;
        vector<int> vec;

        for_each(v, mat[u]) {
            int x = dfs(v);
            vec.pb(x-1);
            d = max(d,x);
        }

        int count = 0;
        for_each(x,vec) {
            int y = x;
            while(big[y] == u) {
                count--;
                big[y++] = -1;
            }

            big[y] = u;
            count++;
            d = max(y,d);
        }

        if(big[d] == u && count>1) d++;

        return d+1;
    };

    cout<<dfs(0)-1;
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
