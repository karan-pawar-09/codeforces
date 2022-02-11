/*
    author:Karan
    created:30.01.2022 20:35:48
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
    int n;
    cin>>n;
    int k=1;
    while((k*2)<=(n-1)) {
        k*=2;
    }
    for(int i=n-1;i>=k;i--) {
        cout<<i<<" ";
    } for(int i=0;i<k;i++) {
        cout<<i<<" ";
    } 
    cout<<endl;
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