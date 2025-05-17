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

// const int s = 500;
ull mp[1000001];
const ull K = 92823987;

void solve()
{
    int n,q; cin>>n>>q;
    int a[n];arr_in(a);
    for_each(v,a) mp[v] = 0;

    vector<ull> pre(n+1);
    u_set<ull> st;

    rep(i,0,n-1) {
        int v = a[i];
        if(mp[v] == 0) {
            ull x = v;
            x = (x+K+x*K);
            mp[v] = x;
        }

        pre[i+1] = pre[i] ^ mp[v];
    }

    int l,r;
    while(q--) {
        cin>>l>>r;

        cout<<(pre[r] ^ pre[l-1]? "NO":"YES")<<endl;
    }

    // for_each(v,a) mp[v] = 0;
    
    // vector<array<int,3>> queries(q);
    // rep(i,0,q-1) {
    //     cin>>queries[i][0]; queries[i][0]--;
    //     cin>>queries[i][1]; queries[i][1]--;
    //     queries[i][2] = i;
    // }

    // sort(queries.begin(), queries.end(),[](array<int,3> &a, array<int,3> &b) {
    //     return make_pair(a[0]/s, a[1]) < make_pair(b[0]/s, b[1]);
    // });

    // vector<bool> ans(q,0);

    // int cl, cr;
    // cl = 0;
    // cr = -1;

    // int count = 0;

    // auto update = [&] (int j) {
    //     mp[a[j]] = !mp[a[j]];
    //     count+= mp[a[j]]?1:-1;
    // };

    // for_each(v, queries) {
    //     int l = v[0];
    //     int r = v[1];
    //     int i = v[2];

    //     while(l<cl) update(--cl);
    //     while(l>cl) update(cl++);
    //     while(r>cr) update(++cr);
    //     while(r<cr) update(cr--);

    //     ans[i] = (count == 0);
    // }

    // rep(i,0,q-1) cout<<(ans[i]?"YES":"NO")<<endl;
}
int main()
{
    fastio;

    test
    {
        solve();
    }

    return 0;
}
