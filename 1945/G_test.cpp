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
struct Node {
    ll k;
    ll s;
    ll t = 0;

    Node() {

    }

    Node(ll k, ll s) {
        this->k = k;
        this->s = s;
    }

    bool operator<(const Node& other) const {
        if (k == other.k) {
            if (t == other.t) {
                return s > other.s;
            }
            return t > other.t;
        }
        return k < other.k;
    }
};

int solve()
{
    int n,d;cin>>n>>d;
    int k[n],s[n];

    rep(i,0,n-1) cin>>k[i]>>s[i];

    int t[n];

    int maxx = k[n-1];
    repi(i,n-1,0) t[i] = max(maxx, k[i]);

    priority_queue<Node> minn;

    u_map<ll, vector<Node>> mp;

    int j = 0;

    rep(i,1,d) {
         Node curr;

        if (minn.size() && minn.top().k > t[j]) {
            curr = minn.top(); minn.pop();
        } else {
            curr = Node((ll)k[j], (ll)s[j]);
            j++;
        }

        curr.t = curr.s + (ll)i;

        mp[curr.t].push_back(curr);

        if(j >= n) return i;

        for_each(p, mp[i]) {
            minn.push(p);
        }

        mp.erase(i);

    }

    return -1;
}
int main()
{
    fastio;

    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}
