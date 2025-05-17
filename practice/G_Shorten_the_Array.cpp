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
    Node* child[2];
    int i;
    Node() {
        i = -1;
        child[0] = child[1] = nullptr;
    }
};

void add(Node* root, bitset<B> &b, int i) {
    repi(j,B-1,0) {
        if(!root->child[b[j]]) root->child[b[j]] = new Node();

        root = root->child[b[j]];
        root->i = i;
    }
}

int getMin(Node* root, bitset<B> &b, bitset<B> &k, int i) {
    int minn = INT_MAX;

    repi(j,B-1,0) {
        if(k[j] == 0 && root->child[1-b[j]]) {
            minn = min(minn, i - root->child[1-b[j]]->i + 1);
        }

        root = root->child[b[j] ^ k[j]];

        if(!root) break;
    }

    if(root) minn = min(minn, i - root->i + 1);

    return minn;
}

void solve()
{
    int n; cin>>n;
    ll k; cin>>k;
    ll a[n]; arr_in(a);

    bitset<B> bk(k);

    int minn = INT_MAX;

    Node* root = new Node();

    rep(i,0,n-1) {
        bitset<B> b(a[i]);
        add(root,b,i);
        minn = min(minn, getMin(root,b,bk,i));
    }

    if(minn == INT_MAX) cout<<-1;
    else cout<<minn;
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
