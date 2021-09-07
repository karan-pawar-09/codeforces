/*
author:Karan
created:26.06.2021 17:49:50
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
    ll n;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second.first>>arr[i].second.second;
        if(arr[i].first==1) {

        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            
            if(arr[i].second.first<=arr[j].second.first) {
                if((arr[i].first==1||arr[i].first==3)&&(arr[j].first==1||arr[j].first==2)) {
                    if(arr[i].second.second>=arr[j].second.first) {
                        ans++;
                    }
                } else {
                    if(arr[i].second.second>arr[j].second.first) {
                        ans++;
                    }
                }
                    
            }
            else {
                if((arr[j].first==1||arr[j].first==3)&&(arr[i].first==1||arr[i].first==2)) {
                    if(arr[j].second.second>=arr[i].second.first) {
                        ans++;
                    }
                }
                else {
                    if(arr[j].second.second>arr[i].second.first) {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}