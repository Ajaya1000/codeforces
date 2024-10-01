// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio				   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);				  \
    cout.tie(0)
#define test  \
    int t;   \
    cin >> t; \
    while (t--)
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

vector<vector<string>> giveAns(vector<vector<string>> orchid) {
    auto ans = orchid;

    int n = orchid.size();
    int m = orchid[0].size();

    auto isRotten = [&](int i, int j) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return orchid[i][j] == "R";
    };

    auto shouldRot = [&](int i, int j) {
        if(isRotten(i-1,j) || isRotten(i+1,j) || isRotten(i,j-1) || isRotten(i,j+1)) return true;
        return false;
    };

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(ans[i][j]=="T" && shouldRot(i,j)) ans[i][j] = "R";
        }
    }

    return ans;
 }

vector<vector<string>> sol(vector<vector<string>> orchid, int d) {
    for(int i=1;i<d;i++)
    orchid = giveAns(orchid);

    return orchid;
}

void solve()
{
    vector<vector<string>> orchid = {{"T","R","_","_"}, {"_","T","T","R"},{"T","T","_","R"}, {"_","_","R","_"}};
    auto ans = sol(orchid, 2);

    for_each(vec, ans) {
        for_each(v,vec) cout<<v<<" ";
        cout<<endl;
    }
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