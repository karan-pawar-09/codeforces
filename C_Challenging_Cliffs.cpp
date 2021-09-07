/*
author:Karan
created:18.06.2021 20:38:51
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
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(all(arr));
        ll sdif = arr[1]-arr[0];
        ll edif = arr[n-1]-arr[n-2];
        ll diff = min(sdif, edif);
        ll pos = -1;
        for(ll i=1;i<n-1;i++){
            if(arr[i+1]-arr[i]<diff){
                diff = arr[i+1]-arr[i];
                pos = i;
            }
        }
        vector<ll> ans;
        if(pos == -1){
            if(sdif<edif){
                ans.push_back(arr[0]);
                for(ll i=2;i<n;i++){
                    ans.push_back(arr[i]);
                }
                ans.push_back(arr[1]);
            }
            else{
                ans.push_back(arr[n-2]);
                for(ll i=0;i<n;i++){
                    if(i!=n-2){
                        ans.push_back(arr[i]);
                    }
                }
            }
        }
        else{
            ans.push_back(arr[pos]);
            for(ll i=pos+2;i<n;i++){
                ans.push_back(arr[i]);
            }
            for(ll i=0;i<pos;i++){
                ans.push_back(arr[i]);
            }
            ans.push_back(arr[pos+1]);
        }
        for(ll i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }   
}