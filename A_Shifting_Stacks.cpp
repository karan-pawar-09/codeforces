#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        bool kk=true;
        ll n,h;
        cin>>n;
        vector<ll> arr(n,0);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
       
        ll balance=0;
        
        for(int i=1;i<n;i++) {
            ll diff=arr[i-1]-i+1;
            if(diff<0) {
                kk=false;
                break;
            }
            arr[i-1]=i-1;
            arr[i]+=diff;
            if(arr[i]<=arr[i-1]) {
                kk=false;
                break;
            }
        }
       if(kk) {
        cout<<"YES"<<endl;    
       }
       else {
           cout<<"NO"<<endl;
       }    
    }
}