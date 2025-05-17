// @itsAj
#include <bits/stdc++.h>
// #include<boost/multiprecision/cpp_int.hpp>
#define fastio                   \ 
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                  \
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

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        
        int req = 0;
        int curr = 0;

        auto getValue = [] (char ch) {
            if(ch=='(') return 1;
            if(ch==')') return -1;
            return 0;
        };

        for(int i = 0; i<n; i++) {
            curr+=getValue(s[i]);
            if(curr<0) { 
                req += abs(curr);
                curr = 0;
            }
        }
        req+=curr;
        set<string> ans;

        // string cs = "";
        function<void(int,int,int,string)> allValues = [&](int i, int tot, int del, string cs) {
            // cout<<i<<" "<<tot<<" "<<del<<" "<<cs<<endl;
            if(i==n && tot == 0 && del == req) { ans.insert(cs);  return; } //if(cs.size())cs.pop_back();
            if(i>=n || tot<0 || del > req) { return; }

            cs.push_back(s[i]);
            allValues(i+1, tot+getValue(s[i]), del, cs);
            cs.pop_back();
            if(getValue(s[i]) != 0) allValues(i+1, tot, del+1,cs);
        };

        allValues(0,0,0,"");

        return vector<string>(ans.begin(),ans.end());
    }
};

void solve()
{
    string s; cin>>s;

    auto vec = Solution().removeInvalidParentheses(s);
    // cout<<vec.size()<<endl;
    for_each(v, vec) cout<<v<<endl;
}
int main()
{

    fastio;

    test
    {   
        // cout<<" for "<<t<<endl;
        solve();
        // cout << endl;
    }

    return 0;
}