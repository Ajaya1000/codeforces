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

struct Node {
    Node* next;
    int val;

    Node(int v) {
        next = nullptr;
        val = v;
    }
};

void solve(int testcase)
{
    int n; cin>>n;
    string s; cin>>s;

    auto val = [](char ch) -> int {
        if(ch == 'T') return 0;
        if(ch == 'I') return 1;
        return 2;
    };

    auto getChar = [](int i) -> char {
        if(i==0) return 'T';
        if(i==1) return 'I';
        return 'L';
    };

    assert(val(getChar(0)) == 0);
    assert(val(getChar(1)) == 1);
    assert(val(getChar(2)) == 2);

    int c[3] = {0,0,0};

    rep(i,0,n-1) c[val(s[i])]++;

    int x[3] = {0,1,2};

    sort(x,x+3, [&](int i, int j) {
        return c[i] < c[j];
    });

    if(c[x[2]] == n) {
        cout<<-1<<endl;
        return;
    }

    bool f[3]={0,0,0}; 

    rep(i,0,n-2) {
        if(val(s[i]) != val(s[i+1])) f[3-val(s[i])-val(s[i+1])] = 1;
    }

    vector<int> seq;

    int poss = 100;

    rep(_,1,c[x[2]]-c[x[1]]) {
        seq.push_back(f[x[0]]?x[0]:x[1]);
        seq.push_back(f[x[0]]?x[1]:x[0]);

        poss-=2;
    }

    rep(i,1,c[x[1]]-c[x[0]]) {
        seq.push_back(f[x[0]]?x[0]:x[1]);
        seq.push_back(f[x[0]]?x[1]:x[0]);
    
        seq.push_back(x[2]);
        seq.push_back(x[0]);
    }

    assert(seq.size() <= 2*n);

    cout<<seq.size()<<endl;

    
    for(auto &v: seq) {
        // cout<<v<<" ";
        string temp;
        bool flag = 0;
        rep(i,0,(int)s.size()-1) {
            temp.push_back(s[i]);

            if((i == (int)s.size()-1) || flag) continue;

            if((val(s[i]) != val(s[i+1])) && (3 == v + val(s[i])+val(s[i+1]))) {
                flag = 1;
                cout<<i+1<<endl;
                temp.push_back(getChar(v));
            }
        }
        assert(flag);
        poss++;
        if(!flag) {
            exit(poss);
        }
        
        // cout<<" "<<temp<<endl;
        s = temp;
    }
}
int main()
{
    fastio;

    test
    {
        solve(t);
        // cout << endl;
    }

    return 0;
}
