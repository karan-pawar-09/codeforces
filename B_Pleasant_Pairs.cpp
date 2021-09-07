/*
author:Karan
created:25.06.2021 21:12:10
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
        ll n;
        cin>>n;
        vector<ll> arr(n);
        vector<ll> loc(2*n+7,1e18+7);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            loc[arr[i]]=i+1;
        }      
        ll ans=0;
        for(ll i=1;i<2*n+7;i++) {
            for(ll j=1;j*j<i;j++){
                if(i%j==0){
                    if(loc[j]+loc[i/j]==i){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}