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

int myOp(int a, int b) {
    return min(a,b);
}

void buildSegTree(int i, int l, int r, int a[]) {
    if(l == r) {
        segment[i] = a[l];
        return;
    }

    int m = l + (r-l)/2;

    buildSegTree(2*i+1, l,m,a);
    buildSegTree(2*i+2, m+1,r,a);

    segment[i] = myOp(segment[2*i+1], segment[2*i+2]);
}

void update(int i, int l, int r, int p, int v) {
    if(p>r || p<l) return;

    if(l == r) {
        segment[i] = v;
        return;
    }

    int m = l + (r-l)/2;

    update(2*i+1, l, m, p, v);
    update(2*i+2, m+1, r, p, v);

    segment[i] = myOp(segment[2*i+1], segment[2*i+2]);
}

int getVal(int i, int l, int r, int l1, int r1) {
    if(l1>r1) return INT_MAX;

    if(r1 < l || l1 > r) return INT_MAX;
    if(l1 <= l && r1 >= r) return segment[i];

    int m = l + (r-l)/2;

    int left = getVal(2*i+1,l,m,l1, r1);
    int right = getVal(2*i+2, m+1,r,l1, r1);

    return myOp(left, right);
}

void solve()
{
    int n,q; cin>>n>>q;
    int a[n]; arr_in(a);

    vector<pii> indices(n);

    vector<int> temp(n+1, -1);

    rep(i,0,n-1) {
        if(temp[a[i]] == -1) {
            indices[i].first = i;
        } else {
            indices[i].first =  temp[a[i]];
        }
        
        temp[a[i]] = i;
    }

    temp = vector<int>(n+1,-1);

    repi(i,n-1,0) {
        if(temp[a[i]] == -1) {
            indices[i].second = i;
        } else {
            indices[i].second =  temp[a[i]];
        }
        
        temp[a[i]] = i;
    }

    int b[n];
    rep(i,0,n-1) b[i] = n;

    buildSegTree(0,0,n-1,b);

    int right[n];

    int r=0;

    update(0,0,n-1, r, indices[r].first);
    rep(l,0,n-1) {
        if(l>0 ) {//&& indices[l-1].second<=r
            update(0,0,n-1,indices[l-1].second, indices[l-1].second);
        }

        auto getLeft = [&](int x) {
            return (indices[x].first < l)? x : indices[x].first;
        };

        while(r<n && getVal(0,0,n-1, getLeft(r+1)+1, r) >= getLeft(r+1)) {
            r++;
            update(0,0,n-1, r, getLeft(r));
        }
      
        right[l] = r;
    }

    int u,v;
    while(q--) {
        cin>>u>>v; u--,v--;
        if(right[u]>=v) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
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
