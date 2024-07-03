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

ll gcd(ll a, ll b) {
    if(a == 0) return b;

    return gcd(b%a,a);
}

bool solve()
{
    int n;cin>>n;
    int a[n];
    arr_in(a);

    int g[n-1];

    rep(i,0,n-2) {
        g[i] = gcd(a[i],a[i+1]);
    }

    auto getA = [&](int i) {
        if(i < 0) return 1;

        if(i>=n) return a[n-2];

        return a[i];
    };

    auto getGCD = [&](int i) {
        if(i <0) return 1;
        if(i>=n-1) return INT_MAX;

        return g[i];
    };

    bool s[n-1];
    memset(s,0,sizeof(s));

    repi(i,n-2,0) { 
        if(getGCD(i)>getGCD(i+1)) break;

        s[i] = 1;
    }

    // for_each(v,s) cout<<v<<" ";
    // cout<<endl;

    bool p[n-1];
    memset(p,0,sizeof(p));

    rep(i,0,n-2) {
        if(getGCD(i)<getGCD(i-1)) break;

        p[i] = 1;
    }

    // for_each(v,p) cout<<v<<" ";
    // cout<<endl;

    rep(i,0,n-1) {
        if(i>=2 && p[i-2] == 0) break;

        
        int left = getGCD(i-2);
        int right = getGCD(i+1);

        int curr = gcd(getA(i-1), getA(i+1));

        // cout<<i<<" "<<left<<" "<<getA(i-1)<<" "<<getA(i+1)<<" "<<right<<" "<<(i>=n-2 || s[i+1])<<endl;
        if((i>=n-2 || s[i+1]) && left <= curr && curr<= right) return 1;
    }

    return 0;
}
int main()
{
    fastio;

    test
    {
        cout<<(solve()?"YES":"NO");
        cout << endl;
    }

    return 0;
}
