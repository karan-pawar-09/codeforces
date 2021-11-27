/*
    author:Karan
    created:26.11.2021 21:19:04
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
    ll n,m;
    cin>>n>>m;
    if(m>(n/2)) {
        cout<<n-m<<endl;
        return;
    }
    ll ans=((n-m)*(n-m+1))/2;
     for(ll i=0;i<1e6+7;i++) {
         if((i*m)<=(n-m)) {
             ll k=m*((i*(i+1))/2);
             ll res=n-m-(i*m);
             k+=((res*(res+1))/2);
             ans=min(ans,k);
         } else {
             break;
         }
     }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}