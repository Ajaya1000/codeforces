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
#define pli pair<ll,int>
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

// struct Node {
//     ll tot,front,back,mid;

//     Node(ll tot,ll front,ll back,ll mid) {
//         this->tot = tot;
//         this->front = front;
//         this->back = back;
//         this->mid = mid;
//     }
// };

// Node* getResult(Node* left, Node* right, ll curr) {
//     ll tot,front,back,mid;

//     tot = max(left->tot + right->tot, left->back + curr + right->front);
//     front = max(left->front + right->tot, left->mid + curr + right->front);
//     back = max(right->back+left->tot, right->mid+curr+left->back);
//     mid = max(left->front + right->back, left->mid + curr, right->mid);

//     return new Node(tot,front,back,mid);
// }
struct Node {
    int i;
    int length;
    array<int,2> flag;
    Node(int i, int length, array<int,2> flag) {
        this->i = i;
        this->length = length;
        this->flag = flag;
    }

    bool value() {
        return (length%2 && flag[0]) || (length%2==0 && (flag[0]||flag[1]));
    }
};

Node* getUnion(Node* left, Node* right, vector<int> &par) {
    // cout<<"getUnion";
    int legth = left->length + right->length;
    array<int,2> flag;
    flag[0] = left->flag[0] + right->flag[left->length % 2];
    flag[1] = left->flag[1] + right->flag[1 - left->length % 2];
    par[right->i] = left->i;

    return new Node(left->i, legth, flag);
}

int divup(int a, int b) {
    return (a+b-1) / b;
}

void solve()
{
    int n; cin>>n;
    ll a[n];arr_in(a);

    vector<Node*> m(n, nullptr);
    vector<int> par(n);
    rep(i,0,n-1) par[i]=i;

    function<int(int)> getPar = [&](int i) -> int {
        if(i<0 || i>=n) return -1;
        if(par[i]==i) return i;
        return par[i] = getPar(par[i]);
    };

    auto getNode = [&] (int i) -> Node* {
        if(i <0 || i>=n ) return nullptr;
        return m[i];
    };

    vector<pli> vec;
    rep(i,0,n-1) vec.pb({a[i],i});

    sort(vec.begin(), vec.end(), [](pli &a, pli &b){
        return a.first > b.first;
    });

    int count = 0;
    int sum = 0;

    ll ans = 0;

    ll maxValue = vec[0].first;
    for_each(v, vec) {
        int i = v.second;
        Node* curr = new Node(i, 1, {v.first==maxValue,0});
        
        Node* left = getNode(getPar(i-1));
        Node* right = getNode(getPar(i+1));

        if(left) { count -= left->value(); sum -= divup(left->length,2); curr = getUnion(left, curr, par);}
        if(right){ count -= right->value(); sum -= divup(right->length,2); curr = getUnion(curr, right, par);}

        m[curr->i] = curr;

        count += curr->value();
        sum += divup(curr->length,2);

        ll temp = (ll)maxValue + (ll)v.first + (ll)sum;
        
        if(count==0) temp--;
        // cout<<curr->length<<" "<<curr->flag[0]<<" "<<curr->flag[1]<<" ";
        // cout<<sum<<" "<<(ll)maxValue + (ll)v.first<<" "<<temp<<endl;
        ans = max(ans, temp);
    }

    cout<<ans;
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
