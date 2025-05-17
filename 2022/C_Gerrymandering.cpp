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
    int n;cin>>n;
    string s[2]; cin>>s[0]>>s[1];

    vector<array<int,3>> dp(n,{-1,-1,-1});

    auto getDP = [&] (int i, int x) {
        if(i==n && x==0) return 0;
        if(i>=n) return -1;

        return dp[i][x];
    };

    auto isA = [](char c) {
        if(c=='A') return 1;
        return 0;
    };
    auto isValid = [&](char c1, char c2, char c3) {
        int count = isA(c1) + isA(c2) + isA(c3);
        return count>=2;
    };

    repi(i,n-1,0) {
        // cout<<endl<<"for i: "<<i;
        rep(x,0,2) {
            int tot = (n-i)*2 - (x?1:0);
            if(tot%3) { dp[i][x]=-1; continue;}
            // cout<<endl<<"inside for: "<<x;  
            int d1,d2;d1=d2=i;
            if(x==1) d2+=1;
            if(x==2) d1+=1;

            if(getDP(i+3,x) != -1) {
                dp[i][x] = max(dp[i][x], getDP(i+3,x) + isValid(s[0][d1],s[0][d1+1],s[0][d1+2]) + isValid(s[1][d2],s[1][d2+1],s[1][d2+2]));
            }

            // cout<<"\tcase 1: "<<getDP(i+2,0);
            if(x!=0 && getDP(i+2,0) != -1) {
                int tempVal;
                if(x==1) tempVal = isValid(s[0][i],s[0][i+1],s[1][i+1]);
                if(x==2) tempVal = isValid(s[1][i],s[1][i+1],s[0][i+1]);
                
                dp[i][x] = max(dp[i][x], getDP(i+2,0) + tempVal);
            }

            if(x==0) {
                if(getDP(i+1,1)!= -1) dp[i][x] = max(dp[i][x], getDP(i+1,1) + isValid(s[0][i],s[1][i],s[1][i+1]));
                if(getDP(i+1,2)!= -1) dp[i][x] = max(dp[i][x], getDP(i+1,2) + isValid(s[0][i],s[1][i],s[0][i+1]));
            }
        }   
    }

    cout<<dp[0][0];
    // cout<<endl;
    // for_each(vec,dp) {
    //     for_each(v,vec) cout<<v<<" ";
    //     cout<<endl;
    // }

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
