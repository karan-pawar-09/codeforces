/*
    author:Karan
    created:23.02.2022 16:16:20
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
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    if(d-b==0) {
        if(f<b)
            cout<<abs(c-a)<<endl;
        else cout<<0<<endl;
    } else if(f-d==0) {
        if(d>b)
            cout<<abs(e-c)<<endl;
        else cout<<0<<endl;
    } else if(f-b==0) {
        if(d<f)
            cout<<abs(e-a)<<endl;
        else cout<<0<<endl;
    } else {
        cout<<0<<endl;
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