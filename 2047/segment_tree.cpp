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
struct Node {
    Node* left;
    Node* right;
    int val;

    Node() {
        left = right = nullptr;
        val = 0;
    }
};
const int N = 10;
class Solution {
public:
    Node* add(Node* root, int l, int r, int v) {
        if(v<l || v>r) {
            // cout<<l<<" "<<r<<" "<<"q1 ";
            // if(root) cout<<root->val;
            // else cout<<"nil";
            // cout<<endl;
            return root;
        }

        if(!root) root = new Node();

        if(l == r) {
            root->val += 1;
            // cout<<l<<" "<<r<<" "<<"q2 "<<root->val<<endl;
            return root;
        }

        int m = l+(r-l)/2;
        root->left = add(root->left,l,m,v);
        root->right = add(root->right,m+1,r,v);

        int tot = 0;
        // cout<<l<<" "<<r<<" "<<"q3 ";
        if(root->left) { 
            tot += root->left->val;
            // cout<<" left: "<<root->left->val<<" ";
        }
        
        if(root->right){ 
            tot += root->right->val;
            //  cout<<" right: "<<root->right->val<<" ";
        }
        // cout<<" final: "<<tot<<" ";

        root->val = tot;

        // cout<<endl;
       
        return root;
    }

    void dfs(Node* root, int l, int r) {
        if(!root) return;
        cout<<l<<" "<<r<<" "<<root->val<<endl;

        int m = l+(r-l)/2;
        dfs(root->left,l,m);
        dfs(root->right,m+1,r);
    }

    int greaterCount(Node* root, int l, int r, int v) {
        if(!root) return 0;
        if(r<=v) return 0;
        if(l>v) { 
            cout<<" 1 -- "<<v<<" "<<l<<" "<<r<<" "<<root->val<<endl;
            return root->val;
        }

        int m = l+(r-l)/2;
        int tot = 0;

        tot += greaterCount(root, l, m, v);
        tot += greaterCount(root, m+1, r, v);

        cout<<" 2 -- "<<v<<" "<<l<<" "<<r<<" "<<tot<<endl;
        return tot;
    }

    vector<int> resultArray(vector<int>& nums) {
        Node* root1 = new Node();
        Node* root2 = new Node();

        vector<int> vec1;
        vector<int> vec2;

        root1 = add(root1, 1, N, nums[0]);
        vec1.push_back(nums[0]);

        root2 = add(root2, 1, N, nums[1]);
        vec2.push_back(nums[1]);

        cout<<" ---- root1  ----\n";
        dfs(root1,1,N);
        cout<<"\n ---- root2  ----\n";
        dfs(root2,1,N);
        cout<<"\n ---- end ----\n";

        for(int i=2;i<nums.size();i++) {
            int g1 = greaterCount(root1, 1, N, nums[i]);
            int g2 = greaterCount(root2, 1, N, nums[i]);

            cout<<g1<<" "<<g2<<endl;
            if(g1 > g2) {
                root1 = add(root1, 1, N, nums[i]);
                vec1.push_back(nums[i]);
            } else if(g1 < g2) {
                root2 = add(root2, 1, N, nums[i]);
                vec2.push_back(nums[i]);
            } else if(vec1.size() >= vec2.size()) {
                root1 = add(root1, 1, N, nums[i]);
                vec1.push_back(nums[i]);
            } else {
                root2 = add(root2, 1, N, nums[i]);
                vec2.push_back(nums[i]);
            }
        }

        for(auto &v: vec2) vec1.push_back(v);
        return vec1;
    }
};

void solve()
{
    vector<int> in = {2,1,3,3};
    auto sol = Solution();
    sol.resultArray(in);
}
int main()
{
#ifndef ONLINE_JUDGE

    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);

#endif
    fastio;

    // test
    {
        solve();
        cout << endl;
    }

    return 0;
}