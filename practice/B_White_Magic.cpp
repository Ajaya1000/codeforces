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

int solve()
{
    int n; cin>>n;
    int a[n]; arr_in(a);

    vector<int> b;
    int minn0 = n;
    rep(i,0,n-1) {
        if(a[i]) b.push_back(i);
        else minn0 = min(minn0,i);
    }
    int m = b.size();

    if(minn0 == n) return m; //no zero
    if(m == 0) return 1; // no non-zero, so any 1 zero

    int minn[m];

    minn[0] = a[b[0]];

    rep(i,1,m-1) {
        minn[i] = minn[i-1];
        minn[i] = min(minn[i], a[b[i]]);
    }

    int curr = 1;
    priority_queue<int,vector<int>,greater<int>> pq;

    int mex[m];

    repi(i,m-1,0) {
        if(a[b[i]]!=0) pq.push(a[b[i]]);

        while (pq.size() && pq.top() <= curr)
        {
            curr = max(curr, pq.top()+1);
            pq.pop();
        }
        
        mex[i] = curr;
    }


    if(minn0 == 0) return m+1;
    rep(i,1,m-1) {
        if(minn[i-1] < mex[i]) return m;
        if(minn0 < b[i]) return m+1;
    }

    return m+1;
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
