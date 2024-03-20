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

struct comp {
    bool operator()(pair<ll,ll> &a, pair<ll,ll> &b) {
        return a.first > b.first;
    }
};

void solve()
{
    int n,m,k,d;cin>>n>>m>>k>>d;

    vector<vector<ll>> mat(n,vector<ll>(m));

    for_each(vec,mat) for_each(v,vec) cin>>v;

    vector<ll> ans;

    rep(i,0,n-1) {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, comp> pq;

        pq.push({1, m-1});

        ll curr;
        repi(j,m-2,0) {
            ll val = -1;
            while(pq.size()) {
                auto t = pq.top();

                if(t.second <= j+d+1) {
                    val = t.first;
                    break;
                }

                 pq.pop();
            }

            if(val<0) exit(5);

            curr = val + mat[i][j] + 1;

            pq.push({curr, j});
        }
        
        ans.pb(curr);
    }

    ll sum = 0;

    rep(i,0,k-1) {
        sum += ans[i];
    }

    ll minn = sum;

    rep(i,k,n-1) {
        sum += ans[i] - ans[i-k];

        minn = min(minn,sum);
    }

    cout<<minn;
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