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
int val(ll v, ll k) {
    if(v>k) return 1;
    return -1;
}

bool isValid(ll a[], int n, ll k, int tot) {
    int curr = tot -  val(a[n-1], k);
    int minn = curr;

    repi(i,n-3,0) {
        curr -= val(a[i+1],k);
        if(curr<= 0 && minn <= curr) return 1;
        minn = min(minn, curr);
        // cout<<minn<<" ";
    }

    return 0;
};
bool solve()
{
    int n; cin>>n;
    ll k; cin>>k;

    ll a[n]; arr_in(a);

    int tot = 0;
    rep(i,0,n-1) tot += val(a[i],k);

    // cout<<"s 1"<<endl;
    if(isValid(a,n,k,tot)) return 1;
    reverse(a,a+n);
    // cout<<"s 2"<<endl;
    if(isValid(a,n,k,tot)) return 1;

    int l = n, r = -1;
    int curr = 0;
    rep(i,0,n-1) {
        curr += val(a[i],k);
        if(curr <= 0) {l = i; break;}
    }

    curr = 0;
    repi(i,n-1,0) {
        curr += val(a[i],k);
        if(curr<=0) {
            r = i;
            break;
        }
    }

    // cout<<"s 3"<<endl;
    return (l<r);
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
