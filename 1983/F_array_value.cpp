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
#define B 30
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

struct Node {
    int i;
    vector<Node*> children;

    Node() {
        children = vector<Node*>(2,nullptr);
        i = -1;
    }
};

void insert(Node* root, bitset<B> &b, int j) {
    repi(i,B-1,0) {
        if(!root->children[b[i]]) root->children[b[i]] = new Node();
        root = root->children[b[i]];
        root->i = max(root->i,j);
    }
}

int query(Node* root, bitset<B> &e, bitset<B> &b) {
    int maxi = -1;
    repi(k,B-1,0) {
        if(e[k]) {
            if(root->children[b[k]]) maxi = max(maxi, root->children[b[k]]->i);
            root = root->children[1-b[k]];
        } else {
            root = root->children[b[k]];
        }

        if(!root) break;
    }

    if(root) {
         maxi = max(maxi, root->i);
    }

    return maxi;
}

int mid(int l, int r) {
    return l + ((r-l) / 2);
}
void solve()
{
    int n; cin>>n;
    ll k; cin>>k;

    ll a[n];
    arr_in(a);

    int l = 0;
    int r = (1<<30) - 1;

    while(l<r) {
        int m = mid(l,r);

        bitset<B> e(m);
        Node* root = new Node();

        ll res = 0;
        int left = -1;
        rep(i,0,n-1) {
            bitset<B> b(a[i]);
            left = max(left, query(root,e,b));
            res += (ll)(left+1);
            insert(root,b,i);
        }
        
        if(res >= k ) r = m;
        else  l = m+1;
    };

    cout<<l;
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
