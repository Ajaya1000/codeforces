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

struct MinComp {
    bool operator()(pii &a, pii &b) {
        return (a.first > b.first) || (a.first == b.first && a.second>b.second);
    }
};

struct MaxComp {
    bool operator()(pii &a, pii &b) {
        return (a.first < b.first) || (a.first == b.first && a.second>b.second);
    }
};

void solve()
{
    int n;cin>>n;
    int a[n];arr_in(a);
    u_map<int,int> mp;
    rep(i,0,n-1) mp[a[i]] = i;
    vector<pii> vp;
    for_each(p,mp) vp.pb(p);
    sort(vp.begin(),vp.end(), [](pii &a, pii &b) {return a.second < b.second;});
    

    priority_queue<pii, vector<pii>, MinComp> minn;
    priority_queue<pii, vector<pii>, MaxComp> maxx;

    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    visited[0] = 1;

    vector<int> ans;

    int i = 0;

    rep(i,0,vp[0].second) {
        minn.push({a[i],i});
        maxx.push({a[i],i});
    }

    int j = 0;
    int x = -1;

    rep(k,1,mp.size()) {
        while(j<n && visited[vp[j].first]) {
            int l = vp[j].second + 1;
            int r = ((j == vp.size() - 1)? n-1: vp[++j].second);
            rep(i,l,r) {
                minn.push({a[i],i});
                maxx.push({a[i],i});
            }
        }
        
        if(k%2) {
            pii top = {-1,-1};
            while(maxx.size()) {
                top = maxx.top();maxx.pop();
                // cout<<"!1 "<<top.first<<" "<<top.second<<endl;
                if(top.second > x && !visited[top.first]) break;
            }
            // cout<<"done"<<endl;
            x = top.second;
            visited[top.first] = 1;
            ans.pb(top.first);
        } else {
            pii top = {-1,-1};
            while(minn.size()) {
                top = minn.top();minn.pop();
                // cout<<"!2 "<<top.first<<" "<<top.second<<endl;
                if(top.second > x && !visited[top.first]) break;
            }
            // cout<<"done"<<endl;
            x = top.second;
            visited[top.first] = 1;
            ans.pb(top.first);
        }
    }

    cout<<ans.size()<<endl;

    for_each(v,ans) cout<<v<<" ";
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
