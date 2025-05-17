#include<iostream>
#include<random>

using namespace std;

const int M = 1e4;

void solve() {
    int n; cin>>n;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,M);

    int r = distrib(gen);

    int a[M]; memset(a,0,sizeof(a));

    for(int i=0;i<M;i++) {
        for(int j=0;j<M;j++){
            a[i] += j%n;
        }

        a[i] += r;
     }

    cout<<a[r]<<" ";
}

int main() {
    int t; cin>>t;
    while (t--)
    {
        solve();
    }
    
}