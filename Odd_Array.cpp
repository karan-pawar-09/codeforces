/*
author:Karan
created:23.08.2021 16:55:15
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll power(long long x, unsigned ll y) {
    ll res = 1; 
    x = x;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x); 
        y = y>>1;
        x = (x*x) ;
    }
    return res;
}

ll upperbound(ll n) {
    ll ans=0;
    ll k;
    for(ll indx=0;indx<=50;indx++) {
        k=power(2,indx);
        if(n%k==0) {
            ans=indx;
        }
    }
    return ans+1;
}
void solve() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++) {
        cout<<upperbound(i)<<" ";
    }
    cout<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}