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
struct MinHeap {
    int k;
    priority_queue<int, vector<int>, greater<int>> minn;

    MinHeap(int k) {
        this->k = k;
        minn = priority_queue<int, vector<int>, greater<int>>();
    }

    void push(int x) {
        minn.push(x);
        while (minn.size() > k) minn.pop();
    }

    int top() {
        return minn.top();
    }

    int size() {
        return minn.size();
    }
};

struct MaxHeap {
    int k;
    priority_queue<int> maxx;

    MaxHeap(int k) {
        this->k = k;
        maxx = priority_queue<int>();
    }

    void push(int x) {
        maxx.push(x);
        while (maxx.size() > k) maxx.pop();
    }

    int top() {
        return maxx.top();
    }

    int size() {
        return maxx.size();
    }
};

pii isect(const pii &a, const pii &b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

void solve()
{
    int n; cin>>n;
    vector<pii> points;

    rep(i,0,n-1) {
        int x,y;
        cin>>x>>y;
        points.pb({x,y});
    }

    sort(points.begin(), points.end());

    // for_each(p, points) {
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

    int l = 0, r = n/4 + 1;
    pii ans;
    while(l<r) {
        int m = l + (r-l)/2;

        if(m == 0) {
            ans = {0,0};
            l = m+1;
            continue;
        }

        auto minn = MinHeap(m);
        auto maxx = MaxHeap(m);

        vector<pii> pre(n);
        rep(i,0,n-1) {
            auto &[x,y] = points[i];
            minn.push(y);
            maxx.push(y);
            pre[i] = {maxx.top()+1, minn.top()};
        }

        minn = MinHeap(m);
        maxx = MaxHeap(m);
        vector<pii> suf(n);
        repi(i,n-1,0) {
            auto &[x,y] = points[i];
            minn.push(y);
            maxx.push(y);
            suf[i] = {maxx.top()+1, minn.top()};
        }

        bool flag = 0;
        // cout<<endl<<"for "<<m<<endl;
        int i=0;
        while(i<n-1) {
            if(points[i].first == points[i+1].first) { i++; continue;}
            auto f = isect(pre[i], suf[i+1]);
            // cout<<"for i="<<i<<" : "<<pre[i].first<<" "<<pre[i].second<<" : "<<suf[i+1].first<<" "<<suf[i+1].second<<endl;
            if(f.first <= f.second) {
                ans = {points[i].first+1, f.first};
                flag = 1;
                break;
            }

            i++;
        }

        if(flag) {
            l = m+1;
        } else {
            r = m;
        }
    }

    cout<<l-1<<endl;
    cout<<ans.first<<" "<<ans.second;
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
