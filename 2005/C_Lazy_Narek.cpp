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
int getInt(char ch) {
    if(ch=='n') return 0;
    if(ch=='a') return 1;
    if(ch=='r') return 2;
    if(ch=='e') return 3;
    if(ch=='k') return 4;

    return -1;
}

void solve()
{
    int n,m;cin>>n>>m;
    vector<string> a(n); arr_in(a);

    vector<long> dp(5);
    repi(i,n-1,0) {
        vector<long> curr(5);
        rep(k,0,4) {
            int x = k;
            long res = 0;
            rep(j,0,m-1) {
                int ci = getInt(a[i][j]);
                if(ci>=0) res--;
                if(ci==x)  { 
                    x = (x+1)%5;
                    if(x==0) res+=10;
                }
            }

            curr[k] = res + dp[x];
        }

        rep(k,0,4) {
            dp[k] = max(dp[k],curr[k]);
        }
    }

    cout<<dp[0];
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
