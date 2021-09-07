/*
author:Karan
created:07.07.2021 21:55:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll ans=0;
        ll n,k,pp;
        cin>>n>>k;
        for(ll i=0;i<n;i++) {
            ans=i^(i-1);
            if(i==0) ans=0;
            cout<<ans<<endl;
            cout.flush();
            cin>>pp;
            if(pp==1) {
                break;
            }
        }  
    }
}