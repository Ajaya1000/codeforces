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
const int N=500005;
int n,rt,c[N][2],a[N],st[N],cnt[N];
ll total, ans[N], dp[N];

void build() {
    int top;
    st[top=0] = -1;
    rep(i,0,n-1) {
        while(top && a[st[top]] > a[i]) top--;
        c[i][0] = st[top+1];
        if(top) c[st[top]][1] = i;
        st[++top] = i;
        st[top+1] = -1;

        // rep(j,0,top+1) cout<<st[j]<<" ";
        // cout<<endl;
    }

    rt = st[1];
}

int giveCount(int u) {
    if(u < 0 ) return 0;
    return cnt[u];
}

void dfs1(int u) {
    if(u < 0) return;

    dfs1(c[u][0]);
    dfs1(c[u][1]);

    ll n1 = giveCount(c[u][0]);
    ll n2 = giveCount(c[u][1]);
    cnt[u] = n1+n2+1;
    // dp[u] = 
    total += (n1+1ll) * (n2+1ll) * (ll) a[u];
}

void dfs2(int u, ll neg) {
    if(u < 0) return;
    int l = c[u][0];
    int r = c[u][1];
    ll n1 = giveCount(l);
    ll n2 = giveCount(r);
    dfs2(l, neg+(n2+1ll)*a[u]);
    dfs2(r, neg+(n1+1ll)*a[u]);

    ll res = total - neg - ((n1+1ll) * (n2+1ll) * (ll) a[u]);

    // cout<<"for u "<<u<<" res "<<res<<endl;
    while(l != -1 && r != -1) {
        if(a[l] < a[r]) {
            // cout<<"left "<<(giveCount(c[l][0]) + 1ll) * cnt[r]*a[l]<< " res ";
            res += (giveCount(c[l][0]) + 1ll) * cnt[r]*a[l];
            l = c[l][1];
            
        } else {
            // cout<<"right "<<(giveCount(c[r][1]) + 1ll) * cnt[l]*a[l]<<" res ";
            res += (giveCount(c[r][1]) + 1ll) * cnt[l]*a[r];
            r = c[r][0];
            
        }
        // cout<<res<<endl;
    }

    ans[u] = res;
}

void solve()
{
    total = 0;
    cin>>n;

    rep(i,0,n) {
        c[i][0] = c[i][1] = -1;
        st[i+1] = -1;
    }

    rep(i,0,n-1) cin>>a[i];

    // rep(i,0,n-1) cout<<a[i]<<" ";
    // cout<<endl;
    build();
    // cout<<rt<<endl;
    // rep(i,0,n-1) cout<<c[i][0]<<" "<<c[i][1]<<endl;
    
    dfs1(rt);
    dfs2(rt,0);
    // cout<<total<<"\t";
    rep(i,0,n-1) cout<<ans[i]<<" ";
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
