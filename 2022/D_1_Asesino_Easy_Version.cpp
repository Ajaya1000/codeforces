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
    int n;
    cin>>n;
    int ans=-1;
    int v1,v2;
    for(int i=n;i>=1;i-=2) {
        if(i==1) {
            ans = 1;
            break;
        }

        cout<<"? "<<i<<" "<<i-1<<endl; cout.flush();
        cin>>v1;
        cout<<"? "<<i-1<<" "<<i<<endl; cout.flush();
        cin>>v2;
        if(v1==v2) continue;
        int j;
        if(i==n) j=1;
        else j=n;

        cout<<"? "<<i<<" "<<j<<endl; cout.flush();
        cin>>v1;
        cout<<"? "<<j<<" "<<i<<endl; cout.flush();
        cin>>v2;

        if(v1!=v2) ans = i;
        else ans = i-1;
        break;
    }

    assert(ans>0);
    cout<<"! "<<ans<<endl; cout.flush();
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
