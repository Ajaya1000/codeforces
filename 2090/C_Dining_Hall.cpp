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

void pre() {
    const int N = 200;
    pii ord[N];
    int pos[N];
    bool visited[N];

    int t = 0;
    int d = 2;
    int ep = 0;
    
    rep(i,0,N-1) pos[i] = 0;

    for(;  t<N; d++) {
        if(d%3==2) {
            for(int x=1;x<d && t<N;x+=3) {
                ord[t++] = {x,d-x};
                pos[ep++] = t-1;
            }
        } else if(d%3 == 0) {
            for(int x=1;x<d-1 && t<N;x++) {
                if(x%3 == 1) ord[t++] = {x,d-x};
                else if(x%3 == 2) ord[t++] = {x,d-x-2}, ord[t++] = {x,d-x};
            }
            
            ord[t++] = {d-1,1};
        }
    }

    rep(i,0,30) {
        cout<<pos[i]<<" ";//<<" "<<ord[pos[i]].first<<" "<<ord[pos[i]].second<<endl;
    }
    cout<<endl<<endl;
}

// void solve()
// {
//     int n; cin>>n;
//     int a[n]; arr_in(a);

//     rep(i,0,4*n-1) visited[i] = 0;

//     int i = 0;
//     int p = 0;

//     rep(j,0,n-1) {
//         if(a[j]) {
//             while(visited[i]) i++;
//             cout<<ord[i].first<<" "<<ord[i].second;
//             visited[i] = 1;
//             i++;
//         } else {
//             while(visited[pos[p]]) p++;
//             cout<<ord[pos[p]].first<<" "<<ord[pos[p]].second;
//             visited[pos[p]] = 1;
//             p++;
//         }
//         // cout<<" "<<i<<" "<<p;
//         cout<<endl;
//     }
// }
int main()
{
    fastio;
    pre();

    // test
    {
        // solve();
    }

    return 0;
}
