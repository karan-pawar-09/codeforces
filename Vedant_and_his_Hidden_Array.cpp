/*
    author:Karan
    created:12.01.2022 21:29:13
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n,a;
    cin>>n>>a;
    if(a%2) {
        if(n%2) {
            cout<<"Odd"<<endl;
        } else {
            cout<<"Even"<<endl;
        }
    } else if(n==1) {
        if(a%2) {
            cout<<"Odd"<<endl;
        } else {
            cout<<"Even"<<endl;
        }
    } else {
        cout<<"Impossible"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}