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
struct Num {
    string s;
    int flag;

    Num(string s, int flag) : s(s), flag(flag) {}

    Num flip() {
        return Num(s, -flag);
    }
};

bool comp(string a, string b) { // true if a < b
    int n = a.size();
    int m = b.size();

    int maxx = max(n,m);

    rep(i,0,maxx-1) {
        if(a[i] < b[i]) return 1;
        if(a[i] > b[i]) return 0;
    }

    return 0;
}

string add(string a, string b) {
    int n = a.size();
    int m = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c="";
    int carry = 0;
    rep(i,0,max(n,m)) {
        int x = 0;
        if(i<n) x += a[i]-'0';
        if(i<m) x += b[i]-'0';
        x += carry;
        carry = x/10;
        x = x%10;
        c += (char)(x+'0');
    }

    assert(carry == 0);

    while(c.size() > 1 &&  c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());
    return c;
}

pair<string,int> subtract(string a, string b) {
    int n = a.size();
    int m = b.size();

    int flag = 1;
    if(comp(a,b)) { swap(a,b); flag = -1; }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c="";
    int carry = 0;
    rep(i,0,max(n,m)+1) {
        int x = 0;
        if(i<n) x += a[i]-'0';
        if(i<m) x -= b[i]-'0';
        x -= carry;
        if(x<0) {
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        c += (char)(x+'0');
    }

    assert(carry == 0);

    while(c.size() > 1 &&  c.back() == '0') c.pop_back();
    reverse(c.begin(), c.end());

    return {c, flag};
}

Num merge(Num a, Num b) {
    if(a.flag == b.flag) {
        string c = add(a.s, b.s);
        return Num(c, a.flag);
    } else {
        auto [c, flag] = subtract(a.s, b.s);
        return Num(c, flag * a.flag);
    }
}

void solve()
{
    string s; cin>>s;
    int n = s.size();
    int flag = 1;

    string curr;
    int curr_flag = 1;

    vector<Num> vec;
    rep(i,0,n-1) {
        if(s[i] == '+' || s[i] == '-' || s[i] == '=') {
            if(curr.size() > 0) {
                Num num(curr, curr_flag * flag);
                curr = "";
                vec.pb(num);
            }

            if(s[i] == '+') {
                curr_flag = 1;
            } else if(s[i] == '-') {
                curr_flag = 0;
            } else {
                curr_flag = 1;
                flag = -1;
            }
        } else {
            curr += s[i];
        }
    }

    // last element
    if(curr.size() > 0) {
        Num num(curr, curr_flag * flag);
        curr = "";
        vec.pb(num);
    }

    // for_each(v, vec) {
    //     if(v.flag == -1) {
    //         cout << "-";
    //     } else {
    //         cout << "+";
    //     }
    //     cout << v.s<<" ";
    // }

    Num tot("0", 1);
    for_each(v, vec) {
        tot = merge(tot, v);
        // cout<<tot.s<<" ";
    }
    
    if(tot.s == "0") {
        cout<<"Correct\n";
        return;
    }


    rep(i,0,(int)vec.size()-1) {
        Num curr = merge(tot, vec[i].flip());
        rep(j,0,(int)vec.size()-1) {
            if(i == j) {
                curr = 
                continue;
            }

            Num a = vec[i];
            Num b = vec[j];
            Num c = merge(a, b);
            if(comp(c.s, tot.s)) {
                cout<<"No\n";
                return;
            }
        }
    }

}
int main()
{
    fastio;

    // test
    {
        solve();
    }

    return 0;
}
