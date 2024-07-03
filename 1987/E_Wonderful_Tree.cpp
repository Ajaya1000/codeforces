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
#define plv pair<ll, deque<ll>>
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
plv dfs(int u, int p, vector<vector<int>> &mat, ll a[]) {
    // cout<<"calling for u "<<u<<endl;
    ll ans = 0;

    ll curr = 0;
    deque<ll> vec;

    bool flag = 0;
    for_each(v,mat[u]) {
        if(v==p) continue;

        auto pr = dfs(v,u,mat,a);
        ans += pr.first;
        curr += a[v];

        if(vec.empty() && !flag) {
            vec = pr.second;
            flag = 1;
            continue;
        }

        flag = 1;
        if(pr.second.empty()) {
            vec = pr.second;
            continue;
        }

        auto getValue = [] (deque<ll> dq, int i) {
            if(i<0 || i>=dq.size()) return 0ll;
            return dq[i];
        };

        deque<ll> temp;
        rep(i,0,min(vec.size(), pr.second.size()) - 1) {
            temp.pb(getValue(vec,i) + getValue(pr.second,i));
        }

        vec = temp;
    }

    cout<<"for u "<<u<<" d is "<<(curr-a[u])<<endl;

    cout<<"Before "<< ans<<"\n";
    for_each(v, vec) cout<<v<<" ";
    cout<<endl;

    if(curr>=a[u]) {
        vec.push_front(curr-a[u]);
    } else if (flag) {
        ll d = a[u]-curr;
        int m = vec.size();

        rep(i,0,m-1) {
            ll minn = min(d,vec[i]);
            d-=minn;
            vec[i] -= minn;
            ans+=minn*ll(i+1);
            
            if(d==0) break;
        }

        if(d>0) {
            ans+=d*(ll)(m+1);
        }

        vec.push_front(0);
    }

    cout<<"After "<< ans<<"\n";
    for_each(v, vec) cout<<v<<" ";
    cout<<endl;
    return {ans, vec};
}

void solve()
{
    int n;cin>>n;

    ll a[n];
    arr_in(a);

    vector<vector<int>> mat(n);

    int u;
    rep(i,1,n-1) {
        cin>>u;
        u--;
        mat[i].pb(u);
        mat[u].pb(i);
    }

    cout<<dfs(0,-1,mat,a).first;
}
int main()
{
    fastio;

    test
    {
        solve();
        cout << endl;
        // cout<<"--------------------------";
        // cout << endl;
    }

    return 0;
}
