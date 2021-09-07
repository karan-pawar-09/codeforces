#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll>arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    if(k==0) {
        if(arr[0]>1) {
            cout<<arr[0]-1<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
    else {
        if(arr[k]==arr[k-1]) {
            cout<<"-1"<<endl;
        }
        else{
            cout<<arr[k-1]<<endl;
        }
    }
    
}