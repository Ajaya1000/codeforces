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

struct Node {
    ll minn, maxx, ans;

    Node() {
        minn = 0;
        maxx = 0;
        ans = 0;
    }

    Node(ll minn, ll maxx, ll ans) {
        this->minn = minn;
        this->maxx = maxx;
        this->ans = ans;
    }

    Node(ll val, int i) {
        maxx = minn = val - (ll)i;
        ans = 0;
    }
};

Node operator+(Node &a, Node &b) {
    ll minn = min(a.minn, b.minn);
    ll maxx = max(a.maxx, b.maxx);
    ll ans = max(max(a.ans, b.ans), b.maxx - a.minn);

    return Node(minn, maxx, ans);
}

struct SegNode {
    Node left, right;

    SegNode() {
        right = left = Node();
    }

    SegNode(Node left, Node right) {
        this->left = left;
        this->right = right;
    }

    SegNode(ll val, int i, int n) {
        left = Node(val, i);
        right = Node(val, n-1-i);
    }
};

SegNode operator+(SegNode &a, SegNode &b) {
    Node left = a.left + b.left;
    Node right = b.right + a.right;

    return SegNode(left, right);
}

const int N = 2*1e5;
vector<SegNode> segment(4*N+4);

void buildSegTree(int i, int l, int r, int n, ll a[]) {
    if(l == r) {
        segment[i] = SegNode(a[l], l, n);
        return;
    }

    int m = l + (r-l)/2;

    buildSegTree(2*i+1, l,m,n,a);
    buildSegTree(2*i+2, m+1,r,n,a);

    segment[i] = segment[2*i+1] + segment[2*i+2];
}

void update(int i, int l, int r, int p, int n, int v) {
    if(p>r || p<l) return;

    if(l == r) {
        segment[i] = SegNode(v, l, n);
        return;
    }

    int m = l + (r-l)/2;

    update(2*i+1, l, m, p, n, v);
    update(2*i+2, m+1, r, p, n, v);

    segment[i] = segment[2*i+1] + segment[2*i+2];
}

// int getVal(int i, int l, int r, int l1, int r1, int a[]) {
//     if(r1 < l || l1 > r) return -1;
//     if(l1 <= l && r1 >= r) return segment[i];

//     int m = l + (r-l)/2;

//     int left = getVal(2*i+1,l,m,l1, r1, a);
//     int right = getVal(2*i+2, m+1,r,l1, r1, a);

//     return myOp(left, right);
// }

void solve()
{
    int n,q; cin>>n>>q;

    ll a[n]; arr_in(a);
    buildSegTree(0,0,n-1,n,a);

    auto printAns = [&]() {
        cout<<max(segment[0].left.ans, segment[0].right.ans)<<endl;
    };

    printAns();
    while(q--) {
        int i;
        ll v;
        cin>>i>>v;
        i--;
        update(0,0,n-1,i,n,v);
        printAns();
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
