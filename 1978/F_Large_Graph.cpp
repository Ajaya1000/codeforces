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
const int N = 1e6;
vector<int> primes(N+1);

void pre() {
    rep(i,0,N) primes[i] = i;

    for (ll i = 2; i <= N; i++) {
        if (primes[i] != i) continue;

        for (ll j = i * i; j <= N; j += i) {
            primes[j] = i;
        }
    }
}

int findParent(int i, int parent[]) {
    if(parent[i] == -1) return i;

    return parent[i] = findParent(parent[i], parent);
}

void setUnion(int u, int v, int parent[]) {
    int up = findParent(u,parent);
    int vp = findParent(v,parent);

    if(up == vp) return;

    parent[up] = vp;
}

void solve()
{
    int n;cin>>n;
    int k;cin>>k;

    int a[n];
    for_each(v,a) cin>>v;

    u_map<int, vector<int>> mp;

    rep(i,0,n-1) {
        int x = a[i];
        while(x > 1) {
            int p = primes[x];

            while(x%p == 0) {
                x /= p;
            }

            mp[p].pb(i);
        }
    }

    int parent[n];
    memset(parent,-1,sizeof(parent));

    for_each(p, mp) {
        auto &vec = p.second;

        rep(i,1,vec.size()-1) {
            int u = vec[i];
            int v = vec[i-1];

            int d = min(u-v, n-u+v);

            if(d > k ) continue;
            setUnion(u,v,parent);
        }
    }

    int count = 0;
    for_each(v,parent) {
        if(v== -1) count++;
    }

    cout<<count;
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
