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
int find_first(bitset<B> n) {
    repi(i,B-1, 0) if(n[i]) return i;
    return B;
}

bool update(int l, int r, ll b[]) {
    bitset<B> n1(b[l]);
    bitset<B> n2(b[r]);

    int i = find_first(n1);
    int j = find_first(n2);
    // cout<<"called "<<b[l]<<" "<<b[r]<<endl;

    ll val = 0;
    while(i >=0 && j>=0 && n1[i] == n2[j]) {
        val = (val<<1) + n1[i];
        i--;
        j--;
    }

    int count = (i+1) + (j+1);
    int temp = r-l - count;
    // cout<<"called "<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<temp<<endl;
    if(temp < 0 || temp%2) {
        return 0;
    }

    rep(x,1,temp) {
        if(x%2) b[x+l] = b[l]/2;
        else b[x+l] = b[l];
    }

    for(int curr = l + temp+1; curr <= l+i+1; curr++) {
        b[curr] = b[curr-1]/2;
        // cout<<"updating-i "<<curr<<"with "<<b[curr-1]/2<<endl;
    }

    for(int curr = r - 1; curr >= r-j; curr--) {
        b[curr] = b[curr+1]/2;
        // cout<<"updating-i "<<curr<<"with "<<b[curr+1]/2<<endl;
    }

    return 1;
}

void solve()
{
    int n;cin>>n;
    ll a[n];
    for_each(v,a) cin>>v;

    ll b[n];

    rep(i,0,n-1) b[i] = a[i];

    bool flag = 0;
    int l = -1;
    rep(i,0,n-1) {
        if(a[i] != -1) {
            flag = 1;
            l = i;
            for(int j = 1;i-j >=0;j++) {
                // if(j%2) b[i-j] = a[i]/2;
                // else b[i-j] = a[i];
                if(b[i-j+1] == 1) b[i-j] = 2;
                else b[i-j] = b[i-j+1]/2;
            }
            break;
        }
    }

    int r = -1;
    repi(i,n-1,0) {
        if(a[i] != -1) {
            flag = 1;
            r = i;
            for(int j = 1;i+j<n;j++) {
                if(b[i+j-1] == 1) b[i+j] = 2;
                else b[i+j] = b[i+j-1]/2;
            }
            break;
        }
    }

    if(!flag){
        rep(i,0,n-1) if(i%2) cout<<2<<" "; else cout<<1<<" ";
        return;
    }

    rep(i,l+1,r) {
        if(a[i] != -1) {
            // cout<<"found "<<a[l]<<endl;
            if(!update(l,i,b)) {
                cout<<-1;
                return;
            }
            l = i;
        }
    }

    rep(i,0,n-1) cout<<b[i]<<" ";
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
