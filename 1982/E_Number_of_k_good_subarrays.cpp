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
#define B 60
//

#define mod 1000000007

typedef unsigned long long ull;
typedef long long ll;
using namespace std;
// using namespace boost::multiprecision;

template <typename T>
inline T modv(T v, T m) { return ((v % m) + m) % m; }

ull _pow(ull n, ull m)
{
    ull res = _pow(n, m / 2);

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
const int K = 62;
vector<vector<ull>> dp(K+1, vector<ull>(K+1,0));
ull p[K+1];
ull p2[K+1];
ull inv2;

void pre() {
    inv2 = _powMod(2,mod-2);

    p[0] = 1;
    p2[0] = 1;
    rep(i,1,K) p[i] = (p[i-1] * 2ll) % mod;
    rep(i,1,K) p2[i] = p2[i-1] * 2ull;

    rep(j,1,K) dp[0][j] = 1;

    rep(j,1,K) {
        ull n = p2[j];
        rep(i,1,j-2) {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%mod;
            
        }

        dp[j-1][j] = (p[j-1] * (p[j]-1))%mod;
       

        ull temp = (p[j-1] * (p[j]+1)) % mod;
        rep(i,j,K) {
            dp[i][j] = temp;
           
        }
    }
}

void solve()
{
    ull n;cin>>n;
    int k;cin>>k;

    bitset<K> b(n);

    int i = K;
    ull sum = 0;
    while(i>=0 && k >= 0) {
        if(!b[i]) {
            i--;
            continue;
        }

        auto val = b.to_ullong();
        // ull curr = p2[k];

        if(i > k) {
            // cout<<"case 1 "<<i<<" "<<k<<" "<<dp[k][i]<<endl;
            sum = (sum + dp[k][i])%mod;
            b[i].flip();
            i--;
            k--;
        } else {
            ull temp = val % mod;
            temp = (((temp * (temp+1)) % mod) * inv2) % mod;
            sum = (sum + temp) % mod;
            // cout<<"case 2 "<<i<<" "<<k<<" "<<temp<<endl;
            
            break;
        }
    }
    
    cout<<sum;
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
