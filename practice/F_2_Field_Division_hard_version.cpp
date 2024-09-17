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
bool comp(pii &a, pii &b) {
    return a.first < b.first;
}

void solve()
{
    int n,m,k;cin>>n>>m>>k;

    map<int,vector<pii>> mp;

    rep(i,0,k-1) {
        int r,c;
        cin>>r>>c;
        r--,c--;
        auto it = mp.find(r);

        mp[r].pb({c,i});
    }

    mp[-1].pb({0,-1});

    for_each(p,mp) {
        sort(p.second.begin(), p.second.end(), comp);
    }

    ull r = 0;
    ull a[k];
    memset(a,0,sizeof(a));

    int lstc = m;
    int lstr = n;

    auto it=mp.rbegin();

    while(it!=mp.rend()) {
        auto &vec = it->second;
        int nxtc = vec.front().first;
        int nxtr = it->first;
        int i = vec.front().second;
        ull temp1 = (ull)(lstr - nxtr - 1) * (ull)(lstc);
        temp1 += (ll)(nxtc);
        r+=temp1;

        if(i < 0) break; 
       
        int currr = nxtr+1;
        int currc = lstc;

        if(vec.size()>1) {
            currc = min(lstc, vec[1].first);
        }

        ull temp = 0;

        it++;
        while(it != mp.rend() && it->second.front().first >= nxtc) {
            // cout<<"inside while "<< ((it->first))<<" "<< it->second.first<<endl;
            temp += (ull)(currr - (it->first) - 1) * (ull)(currc-nxtc);
            currc = min(currc, it->second.front().first);
            temp += (ull)(currc-nxtc);
            currr = it->first;
            it++;
        }

        temp += (ull)(currr - (it == mp.rend() ? -1 : it->first) - 1) * (ull)(currc-nxtc);

        // cout<<"i: "<<i<<" "<<temp<<" "<<temp1<<endl;

        a[i] = temp;

        lstc = nxtc;      
        lstr=nxtr;
    }

    cout<<r<<endl;
    rep(i,0,k-1) {
        cout<<a[i]<<" ";
    }
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
