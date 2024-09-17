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
const int N = 2*1e5;
vector<int> segment(4*N+4);

void buildSegTree(int i, int l, int r, int a[]) {
    if(l == r) {
        segment[i] = a[l];
        return;
    }

    int m = l + (r-l)/2;

    buildSegTree(2*i+1, l,m,a);
    buildSegTree(2*i+2, m+1,r,a);

    segment[i] = max(segment[2*i+1], segment[2*i+2]);
}

int getMax(int i, int l, int r, int l1, int r1, int a[]) {
    if(r1 < l || l1 > r) return -1;
    if(l1 <= l && r1 >= r) return segment[i];

    int m = l + (r-l)/2;

    int left = getMax(2*i+1,l,m,l1, r1, a);
    int right = getMax(2*i+2, m+1,r,l1, r1, a);

    return max(left, right);
}

void solve()
{
    string s;cin>>s;

    int n = s.size();
    int pre[n];

    int sum;
    sum = 0;
    map<int,vector<int>> mp;

    rep(i,0,n-1) {
        if(s[i] == '(') sum++;
        else sum--;
        pre[i] = sum;
        mp[pre[i]].pb(i);
    }

    buildSegTree(0,0,n-1,pre);
    ll ans = 0;

    for_each(p, mp) {
        int curr = p.first;
        auto &vec = p.second;

        int m = vec.size();
        if(m < 2) continue;

        int i = 0;
        rep(j,1,m-1) {
            while(i<j && getMax(0,0,n-1,vec[i]+1, vec[j], pre) - curr > curr) i++;
            ans+=(j-i);
        }
    }

    cout<<ans;
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
