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

bool solve()
{
    int n,m; cin>>n>>m;
    string a,b; cin>>a>>b;

    auto getQueue = [](int n, string &a) {    
        deque<pair<int,bool>> q;

        int curr = 1;

        rep(i,1,n-1) {
            if(a[i] != a[i-1]) {
                q.push_back({curr, a[i-1]-'0'});
                curr = 0;
            }
            curr++;
        }

        q.push_back({curr, a[n-1]-'0'});
        return q;
    };

    auto q1 = getQueue(n,a);
    auto q2 = getQueue(m,b);

    if(q2.size() && q2.front().second == 1) {
        if(q1.size() && q1.front().second == 1 && q1.front().first >= q2.front().first) {
            q1.pop_front();
            q2.pop_front();
        } else return 0;
    }

    if(q2.size() && q2.back().second == 1) {
        if(q1.size() && q1.back().second == 1 && q1.back().first >= q2.back().first) {
            q1.pop_back();
            q2.pop_back();
        } else return 0;
    }

    if(q1.size() && q1.front().second == 1) q1.pop_front();
    if(q1.size() && q1.back().second == 1) q1.pop_back();

    if(q2.empty() && q1.size()) return 0;

    while(q1.size() && q2.size()) {
        if(q2.front().second == 0) {
            if(q1.front().second == 0) q2.front().first -= q1.front().first;
            q1.pop_front();
            if(q2.front().first <= 0) q2.pop_front();
        } else {
            if(q1.front().second == 1 && q1.front().first >= q2.front().first) {
                q1.pop_front();
                q2.pop_front();
            } else {
                q1.pop_front();
            }
        }
    }

    return q2.empty();
}
int main()
{
    fastio;

    test
    {
        cout<<(solve()?"yes":"no");
        cout << endl;
    }

    return 0;
}