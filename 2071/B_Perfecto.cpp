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

const int N=5e5;
vector<int> imp;

void pre() {
    ll sum = 0;
    for(int i=1;i<=N;i++) {
        sum += (ll) i;
        ll rt = sqrt(sum);
        if(rt*rt == sum) {
            imp.push_back(i);
        }
    }
    cout<<endl;
}

void solve()
{
    int n; cin>>n;
    vector<int> ans;
    rep(i,1,n) ans.pb(i);

    for_each(v, imp) {
        if(v > n) break;

        if(v == n) {
            cout<<-1;
            return;
        }

        swap(ans[v-1], ans[v]);
    }
    

    for_each(v,ans) {
        cout<<v<<" ";
    }
}
int main()
{
    fastio;
    pre();
    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
