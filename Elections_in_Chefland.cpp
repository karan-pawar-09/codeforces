/*
    author:Karan
    created:19.01.2022 20:41:29
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
    int a,b,c;
    cin>>a>>b>>c;
    if(a>(b+c)) {
        cout<<"A"<<endl;
    } else if( b> (a+c)) {
        cout<<"B"<<endl;
    } else if( c>(a+b)) {
        cout<<"C"<<endl;
    } else {
        cout<<"NOTA"<<endl;
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