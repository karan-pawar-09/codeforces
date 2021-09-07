/*
author:Karan
created:09.08.2021 20:07:01
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
        sort(all(arr),greater<ll>());
        ll maxi=arr[0];
        ll k=0;
        ll sum=0;
        ll no=0;
        for(ll i=0;i<n;i++) {            
            sum+=arr[i];
            no++;            
        }
        long double ans=maxi;  
        cout<<fixed;
        cout<<setprecision(10);
        cout<<ans+(((long double)(sum-maxi))/(no-1))<<endl;
       
    }
}