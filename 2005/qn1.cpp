// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                  \
    cout.tie(0)
#define test  \
    int t;   \
    cin >> t; \
    while (t--)
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
    if(n%2) {
        cout<<-1<<" "<<-1<<endl;
        return;
    }

    int x = n;

    n = n/2;

    

    bool a[32];
    memset(a,0,sizeof(a));

    for(int i=0; i<32; i++) {
        a[i] = (n%2);
        n=n/2;
    }

    vector<pair<int, int>> ans;
    ans.push_back({0,0});

    for(int i=0;i<=log2(x);i++) {
        vector<pair<int, int>> res;

        auto push = [&](int f, int s) {
            if(f+s<=x) {
                res.push_back({f,s});
            }
        };

        for(auto p: ans) {
            if(a[i]) {
                 push((1<<i)+ p.first, p.second);
                 push(p.first, (1<<i) + p.second);
            } else {
                 push(p.first, p.second);
                 push((1<<i)+ p.first, (1<<i) + p.second);
            }
        }

        ans = res;
    }

    // cout<<ans.size()<<endl;

    bool hasSome = 0;
    for(auto &p: ans) {
        if(p.first+p.second == x) {
            hasSome = 1;
            cout<<p.first<<" "<<p.second<<endl;
        }
    }

    if(!hasSome) {
        cout<<-1<<" "<<-1<<endl;
    }
}
int main()
{
    fastio;

    test
    {
        solve();
        // cout << endl;
    }

    return 0;
}