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

bool isvalid(int count, int size) {
    return (2*count >= size);
}

void solve()
{
    int n;cin>>n;
    string s;cin>>s;

    int total = 0;
    rep(i,0,n-1) total += (s[i]-'0');

    int val = -n-2;

    if(2*total >= n) val = -1;

    auto rank = [&] (int x) { 
        return abs(n-2*x-2);
    };

    int curr = 0;
    // cout<<"printing : ";
    rep(i,0,n-1) {
        curr += (s[i]-'0');
        if(isvalid(i+1 - curr, i+1) && isvalid(total - curr, n-i-1) && rank(i) < rank(val)) {
                val = i;
        } 
    }
    // cout<<endl;
    cout<<val+1;
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
