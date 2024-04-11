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

long getSum(long n) {
    long ans = (n * (n + 1)) / 2;

    return ans;
}

bool comp(const pii &a, const pii &b) {
    if(a.first < b.first) return true;

    return false;
}

void solve()
{
    int n,q;cin>>n>>q;

    string s; cin>>s;

    vector<pii> vec1,vec2;

    int curr = 0;

    rep(i,0,n-1) {
        if(s[curr] != s[i]) {
            vec1.pb({curr,i-1});
            curr = i;
        }
    }
    // last group
    vec1.pb({curr,n-1});

    curr = 0;
    rep(i,2,n-1) {
        if(s[i-2] != s[i]) {
            // cout<<i<<" ";
            if(i-curr >= 3) vec2.pb({curr,i-1});
            curr = i-1;
        }
    }

    if(n-1-curr >= 3) vec2.pb({curr, n-1});

    for_each(p,vec2) cout<<p.first<<" "<<p.second<<endl;
    int l,r;
    while(q--) {
        cin>>l>>r; l--,r--;

        long ln = r-l+1;
        
        auto it = upper_bound(vec1.begin(),vec1.end(), pii(l,0), comp);

        if(it != vec1.begin()) {
            it--;
            cout<<"1 "<<it->first<<" "<<it->second<<"\t";
            if (it->first <= l && it->second >= r) {
                cout<<"1 "<<0<<endl;
                continue;
            }
        }

        auto it2 = upper_bound(vec2.begin(),vec2.end(), pii(l,0), comp);

        if(it2 != vec2.begin()) {
            it2--;
            cout<<"2 "<<it2->first<<" "<<it2->second<<"\t";
            if (it2->first <= l && it2->second >= r) {
                cout<<"2 "<<getSum(ln/2)<<endl;
                continue;
            }
        }

        cout<<"3 "<<getSum(ln)-1<<endl;
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
