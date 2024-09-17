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
const int N=6;
void solve()
{   string str[] = {"BG", "BR", "BY", "GR", "GY", "RY"};
    u_map<string,int> m;
    rep(i,0,N-1) m[str[i]] = i;

    int n,q;cin>>n>>q;
    int a[n];

    rep(i,0,n-1) {
        string s;cin>>s;
        a[i] = m[s];
    }

    int pre[N][n];
    int suf[N][n];

    rep(i,0,n-1) {
        rep(j,0,N-1) {
            pre[j][i] = (i>0)? pre[j][i-1] : -1;
        }
        pre[a[i]][i] = i;
    }

    repi(i,n-1,0) {
        rep(j,0,N-1) {
            suf[j][i] = (i<n-1)? suf[j][i+1] : n;
        }
        suf[a[i]][i] = i;
    }

    rep(_,0,q-1) {
        int i,j;
        cin>>i>>j;
        i--,j--;
        if(j<i) swap(i,j);
        if(a[i]+a[j] != 5) {
            cout<<(j-i)<<endl;
            continue;
        }

        int minn = INT_MAX;
        rep(k,0,N-1) {
            if(k==a[i] || k==a[j]) continue;

            if(pre[k][j] > i) minn = min(minn, j-i);

            if(pre[k][i] != -1) minn = min(minn, (j-i) + 2*(i-pre[k][i]));

            if(suf[k][j] != n) minn = min(minn, (j-i) + 2*(suf[k][j]-j));
        }
        if(minn == INT_MAX) cout<<-1;
        else cout<<minn;
        cout<<endl;
    }
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
