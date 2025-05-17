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

ll kaden(vector<ll> &a, int l, int r, int m) {
    ll sum = 0;
    ll ans = 0;

    rep(i,l,r) {
        int v = a[i]*m;
        sum+=v;
        ans = max(ans, sum);
        if(sum<0) sum = 0;
    }

    return ans*m;
}

pair<ll,ll> range(vector<ll> &a, int l, int r) {
    // cout<<"range "<<l<<" "<<r<<endl;
    return {kaden(a,l,r,-1), kaden(a,l,r,1)};
}

void add(pair<ll,ll> &p, set<ll> &s) {
    // cout<<"add "<<p.first<<" "<<p.second<<endl;
    rep(i,p.first,p.second) s.insert(i);
}

void printSet(set<ll> &s) {
    cout<<s.size()<<endl;
    for_each(v,s) cout<<v<<" ";
}

void solve()
{
    int n; cin>>n;
    vector<ll> a(n); arr_in(a);
    int x,xi = -1;

    rep(i,0,n-1) {
        if(a[i] != -1 && a[i] != 1) {
            x = a[i];
            xi = i;
            // cout<<"at "<<i<<endl;
            break;
        }
    }
    set<ll> ans;

    if(xi == -1) {
        auto r = range(a,0,n-1);
        add(r,ans);
        printSet(ans);
        return;
    }

    auto r1 = range(a,0,xi-1);
    auto r2 = range(a,xi+1,n-1);
    add(r1,ans); add(r2,ans);

    pair<ll,ll> mr1,mr2;
    ll curr=0;
    repi(i,xi-1,0) {
        curr+=a[i];
        mr1.first = min(mr1.first, curr);
        mr1.second = max(mr1.second, curr);
    }
    curr=0;
    rep(i,xi+1,n-1) {
        curr+=a[i];
        mr2.first = min(mr2.first, curr);
        mr2.second = max(mr2.second, curr);
    }

    // cout<<mr1.first<<" "<<mr1.second<<"  --  "<<mr2.first<<" "<<mr2.second<<endl;

    int minn = x;
    if(mr1.first < 0) minn += mr1.first;
    if(mr2.first < 0) minn += mr2.first;

    int maxx = x;
    if(mr1.second > 0) maxx += mr1.second;
    if(mr2.second > 0) maxx += mr2.second;

    pair<ll,ll> r = {minn,maxx};
    add(r,ans);

    printSet(ans);
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
