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

// void fill(int n, int k, vector<int> &vec) {
//     if(n==1) {
//         vec.push_back(1);
//         return;
//     }
    
//     vector<int> left;
//     vector<int> right;
    
//     repi(i,n-2,0) {
//         int p = 1<<i;
//         if(k&p) continue;

//         left.pb()

//     }
// }

void solve()
{
    ll n,k; cin>>n>>k;

    k--;
    bitset<B> bk(k);

    deque<int> vec = {1};

    rep(i,0,min(n-2ll, (ll)B-1ll)) {
        for_each(v,vec) v++;
    
        if(bk[i]) {
            vec.push_back(1);
            bk[i] = 0;
        } else {
            vec.push_front(1);
        }

        if(!bk.any()) break;
    }

    if(bk.any()) { 
        cout<<-1;
        return;
    }

    ll l = n-vec.size();
    if(l>0) rep(i,1ll,l) cout<<i<<" ";
    for_each(v,vec) cout<<v+l<<" ";
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
