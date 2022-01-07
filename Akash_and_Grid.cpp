/*
    author:Karan
    created:05.01.2022 20:58:07
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
    int a=(n+1)/2;
    int b=(n+1)/2;
    int x,y;
    cin>>x>>y;
    if((abs(abs(x)-abs(a))+abs(abs(y)-abs(b)))%2==0) {
        cout<<0<<endl;
    } else {
        cout<<1<<endl;
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