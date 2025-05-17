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

void solve()
{
    int n; cin>>n;
    if(n%2==0) {
        for(int i=0;i<n;i+=2) {
            cout<<i+1<<" "<<i+1<<" ";
        }

        return;
    }

    if(n == 27) {
        int ans[27];
        ans[0] = ans[9] = ans[25] = 1;
        ans[22] = ans[26] = 23;
        ans[23] = ans[24] = 24;

        for(int i=1;i<9;i+=2) ans[i] = ans[i+1] = i+1;
        for(int i=10;i<22;i+=2) ans[i] = ans[i+1] = i+1;

        for_each(v,ans) cout<<v<<" ";
        // for(int i=30;i<=n;i+=2) cout<<i<<" "<<i<<endl;
        return;
    }

    if(n<29) {
        cout<<-1;
        return;
    }

    int ans[29];
    ans[0] = ans[9] = ans[25] = 1;
    ans[24] = ans[28] = 25;
    ans[26] = ans[27] = 27;

    for(int i=1;i<9;i+=2) ans[i] = ans[i+1] = i+1;
    for(int i=10;i<24;i+=2) ans[i] = ans[i+1] = i+1;

    for_each(v,ans) cout<<v<<" ";
    for(int i=30;i<=n;i+=2) cout<<i<<" "<<i<<endl;

    return;
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
