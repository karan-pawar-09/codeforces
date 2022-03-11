/*
    author:Karan
    created:05.03.2022 17:30:58
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
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    long double ans=0;
    if(x<=b) {
     ans =(long double) c/(b-a);
    }
    if(x<=a) {
        ans=1;
    }
    cout<<setprecision(12);
    cout<<fixed;    
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    while(t--) {
        solve();
    }
}