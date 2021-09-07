/*
author:Karan
created:13.06.2021 21:35:59
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
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
        ll ans=0;
        if(n==1) {
            ans=arr[0];
        }
        else if(n==2) {
            ans=arr[0]+arr[1];
        }
        else{
            for(ll i=1;i<n;i++) {
                ans+=abs(arr[i]-arr[i-1]);
            }
            ans+=arr[0]+arr[n-1];
            for(ll i=1;i<n-1;i++) {
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) {
                    ans-=arr[i]-max(arr[i-1],arr[i+1]);
                }
            }
            if(arr[0]>arr[1]) {
                ans-=arr[0]-arr[1];
            }
            if(arr[n-1]>arr[n-2]) {
                ans-=arr[n-1]-arr[n-2];
            }
        }
        cout<<ans<<endl;
        
    }
}