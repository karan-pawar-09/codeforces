#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    bool ans=true;
    while(arr[0]%2==0){
            arr[0]=arr[0]/2;
        }
    long previus=arr[0];
    for(int i=1;i<n;i++) {
        while(arr[i]%2==0){
            arr[i]=arr[i]/2;
        }
        
       
            if(previus!=arr[i]) {
                ans=false;
               break;
            }
        
        
    }
  //  sort(arr.begin(),arr.end());
    
    if(ans){
        cout<<"YES";
    }
    else {
        cout<<"NO";
    }
}