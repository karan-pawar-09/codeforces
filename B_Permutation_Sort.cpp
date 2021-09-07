/*
authot:Karan
created:16.05.2021 13:37:34
*/
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
        bool sorted=true;
        for(ll i=0;i<n;i++) {
            if(arr[i]!=(i+1)) {
                sorted=false;
                break;
            }
        }
        if(sorted) {
            cout<<"0"<<endl;
        }
        else if((arr[0]==1)||(arr[n-1]==n)) {
            cout<<"1"<<endl;
        }
        else if(arr[0]==n&&arr[n-1]==1){
            cout<<"3"<<endl;
        }
        else  {
            cout<<"2"<<endl;
        }
     
    }
    
}