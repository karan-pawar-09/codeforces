#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;  
        vector<pair<int,int> > arr(m);      
        for(ll i=0;i<m;i++) {
            ll a,b;
            cin>>a>>b;
            arr[i].first=b;
            arr[i].second=a;
        }

        sort(arr.begin(), arr.end()); 
        bool ans=true;
        for(ll i=0;i<m-1;i++) {
            if(arr[i].first==arr[i+1].first) {
                ans=false;
            }
            if(arr[i].first==arr[i+1].first+1){
                if(arr[i].second!=arr[i+1].second) {
                    ans=false;
                }
            }
            if(arr[i+1].first==arr[i].first+1){
                if(arr[i+1].second!=arr[i].second) {
                    ans=false;
                }
            }
        }
        for(ll i=0;i<m-1;i++) {
            if(arr[i].first==arr[i+1].first) {
                ans=false;
            }
            if(arr[i].first==arr[i+1].first+1) {
                if(arr[i].second!=arr[i+1].second) {
                    ans=false;
                }
            }
        }

        if(ans) {
            cout<<"1"<<endl;
        }
        else {
            cout<<"0"<<endl;
        }
        
    }
}