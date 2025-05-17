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
    int n,k; cin>>n>>k;

    vector<int> a(n); arr_in(a);

    multiset<int> s(a.begin(), a.end());

    int ans = 0;
    while(s.size()>2) {
        int x = *s.begin();
        int y = k-1-x;
        if(y<x) break;

        auto it = s.upper_bound(y);
        assert(it != s.begin());
        if(it == s.end()) it--;
        assert(it != s.begin());
        it--;

        if(it == s.begin()) break;

        s.erase(it);
        s.erase(s.begin());
        auto lst = s.end(); lst--;
        s.erase(lst);

        ans++;
    }

    int count = 0;
    for_each(v, s) count += (v < k);

    if(2*count >= s.size()) ans += (s.size() + 1) / 2;
    else ans += s.size() - count;
    return ans;
}
int main()
{
    fastio;

    test
    {
        cout<<solve()-1;
        cout << endl;
    }

    return 0;
}
