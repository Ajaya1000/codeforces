// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define test  \
    int t;    \
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

bool comp(pair<ll,ll> &a, pair<ll,ll> &b) {
    return (a.second < b.second);
}

void solve()
{
    int n;cin>>n;

    ll l;cin>>l;

    vector<pair<ll,ll>> vec(n);
    multiset<ll> s;

    rep(i,0,n-1) cin>>vec[i].first>>vec[i].second;

    sort(vec.begin(),vec.end(),comp);

    size_t maxx = 0;

    rep(i,0,n-1) {
        priority_queue<ll> pq;
        ll x = 0;
        rep(j,i,n-1) {
            x+=vec[j].first;
            pq.push(vec[j].first);

            while((x>l-vec[j].second + vec[i].second) && pq.size()) {
                x-=pq.top();
                pq.pop();
            }

            maxx = max(maxx,pq.size());
        }
    }

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