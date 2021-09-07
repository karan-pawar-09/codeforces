#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        {                 
            bool inc=true;
            bool samediff=true;
            for(ll i=1;i<n;i++) {
                if(arr[i]<arr[i-1]) {
                    inc=false;
                    break;
                }
            } 
            if(inc) {
                ll diff=arr[1]-arr[0];
                for(ll i=1;i<n;i++) {
                    if(arr[i]-arr[i-1]!=diff) {
                        samediff=false;
                        break;
                    }
                }
                if(n==1) {
                    cout<<"-1"<<endl;
                }
                else {
                    if(samediff) {
                    cout<<"0"<<endl;
                }
                else {
                    cout<<"-1"<<endl;
                   
                }
                }
                
             
            }   
            else {
                ll pos_diff=0;
                ll neg_diff=0;
                for(ll i=1;i<n;i++) {
                    if(arr[i]>arr[i-1]) {
                        pos_diff=arr[i]-arr[i-1];
                        break;
                    }
                }
                for(ll i=1;i<n;i++) {
                    if(arr[i]<arr[i-1]) {
                        neg_diff=arr[i]-arr[i-1];
                        break;
                    }
                }
                ll m=(pos_diff)-(neg_diff);
                ll diff=(arr[1]-arr[0])%m;
                ll ans=true;
                for(ll i=1;i<n;i++) {
                    if(((arr[i]-arr[i-1])%m+m)%m!=diff) {
                        ans=false;
                        break;
                    }
                }
                for(ll i=0;i<n;i++) {
                    if(arr[i]>=m) {
                        ans=false;
                    }
                    break;
                }
                if(ans) {
                    cout<<m<<" "<<pos_diff<<endl;
                }
                else {
                    cout<<"-1"<<endl;
                }
                
            }  
                        
        }
    }
}