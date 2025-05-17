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

int divup(int a, int b) {
    return (a+b-1) / b;
}

const int N = 10e5;

vector<bool> isPrime(N+1,true);
vector<int> primes;

void pre() {
    for (ll i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve()
{
    int n; cin>>n;
    int l = divup(n,3);
    int r = divup(2*n,3);

    auto it = lower_bound(primes.begin(),primes.end(), l);
    if(it == primes.end()) {
        exit(101);
    }
    int p = *it;

    vector<bool> f(n,0);

    auto out = [&] (int x) {
        if(x<=0 || x>n) exit(102);
        cout<<x<<" ";
        f[x-1] = 1;
    };

    out(p);
    rep(i,1,(n/3) - 1) {
        out(p-i);
        out(p+i);
    }

    for(int i = 0; i<n; i++) {
        if(!f[i]) out(i+1);
    }
}
int main()
{
    fastio;
    pre();
    test
    {
        solve();
        cout << endl;
    }

    return 0;
}
