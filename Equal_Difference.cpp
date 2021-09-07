/*
author:Karan
created:22.08.2021 21:33:05
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
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        if(n<=2) {
            cout<<0<<endl;
        }
        else {
        map<ll,ll> M;
        for(ll i=0;i<n;i++) {
            M[arr[i]]++;
        }
        ll mx=0;
        for(auto x:M) {
            mx=max(mx,x.second);
        }        
        
        if(mx==1) {
            cout<<n-2<<endl;
        }
        else
            cout<<n-mx<<endl;
        
        }     
    }
}