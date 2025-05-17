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
    string s; cin>>s;
    int n = s.size();
    int m = n/2;
    int a[2][26]; memset(a,0,sizeof(a));

    rep(i,0,n-1) {
        a[i/m][s[i]-'a']++;
    }

    int f = 1;
    rep(i,0,25) f &= (a[0][i] == a[1][i]);

    if(f) {
        int l = 0;
        while(l<m && s[l] == s[n-1-l]) l++;

        int r = 0;
        while(r<m && s[m-1-r] == s[m+r]) r++;
        r = m-1-r;

        if(r<=l) return 0;
        return r-l+1;
    }

    int l = 0;
    while(l<m && s[l] == s[n-1-l]) {
        a[0][s[l]-'a'] -= 1;
        a[1][s[l]-'a'] -= 1;
        l++;
    }

    int r = n-1-l;

    int c[26]; memset(c,0,sizeof(c));

    int x = l;
    while(x<m) {
        int j = s[x]-'a';
        int tot = a[0][j]+a[1][j];
        assert(tot%2 == 0);

        if(c[j] < (tot/2)) {
            c[j]++;
            x++;
        } else break;
    }
    assert(x<m);

    memset(c,0,sizeof(c));
    int y = r;
    while(y>=m) {
        int j = s[y]-'a';
        int tot = a[0][j]+a[1][j];
        assert(tot%2 == 0);

        if(c[j] < (tot/2)) {
            c[j]++;
            y--;
        } else break;
    }

    return min(r-x+1, y-l+1);

    

    // debugPrint(l);
    // cout<<n<<" "<<l<<" "<<r<<endl;
    // return r-l+1;
}
int main()
{
    fastio;

    test
    {
        cout<<solve();
        cout << endl;
    }

    return 0;
}
