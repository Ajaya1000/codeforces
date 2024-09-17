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
vector<vector<ull>> getSparseTable(ull a[], int n) {
    const int LG = log2(n)+1;
    vector<vector<ull>> sp(LG+1,vector<ull>(n));

    rep(j,0,n-1) sp[0][j] = a[j];

    rep(i,1,LG) rep(j,0,n-(1<<i)) {
        sp[i][j] = __gcd(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
    }

    return sp;
}

ull getValue(int l, int r, int n, vector<vector<ull>> &sp) {
    if(l>r) return 0;

    int i = log2(r-l+1);
    assert(i<sp.size());

    return min(sp[i][l], sp[i][r-(1<<i)+1]);
}

void solve()
{
    int n; cin>>n;

    ull a[n]; arr_in(a);
    ull b[n]; arr_in(b);

    auto spa = getSparseTable(a,n);
    auto spb = getSparseTable(b,n);

    // rep(l,0,n-1) {
    //    ull curra = 0;
    //     ull currb = 0;
    //     rep(r,l,n-1) {
    //         curra = __gcd(curra, a[r]);
    //         currb = __gcd(currb, b[r]);
    //         auto mida = getValue(l,r,n,spa);
    //         auto midb = getValue(l,r,n,spb);
// assert(mida == curra);
//             assert(midb == currb);
           
    //     }
    // }

    ull maxx = 0;
    ull maxxCount = 1;

    rep(l,0,n-1) {
        // ull curra = 0;
        // ull currb = 0;
        auto lefta = getValue(0,l-1,n,spa);
        auto leftb = getValue(0,l-1,n,spb);
        cout<<"for "<<l<<endl;
        cout<<lefta<<" "<<leftb<<endl;
        rep(r,l,n-1) {
            // curra = __gcd(curra, a[r]);
            // currb = __gcd(currb, b[r]);

            auto mida = getValue(l,r,n,spa);
            auto midb = getValue(l,r,n,spb);

            auto righta = getValue(r+1,n-1,n,spa);
            auto rightb = getValue(r+1,n-1,n,spb);

            // assert(mida == curra);
            // assert(midb == currb);

            ull ans1 = __gcd(__gcd(lefta, righta), midb);
            ull ans2 = __gcd(__gcd(leftb, rightb), mida);

            ull curr =  ans1 + ans2;

            if(curr > maxx) {
                cout<<r<<endl;
                maxx = curr;
                maxxCount = 1;
            } else if(curr == maxx) {
                cout<<r<<endl;
                maxxCount++;
            }
        }
    }

    cout<<maxx<<" "<<maxxCount;
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
