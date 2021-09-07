#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int ans=0;
    if(n==1) {
        cout<<"0"<<endl;
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=1;i<n;i++) {
            if((arr[i]+arr[i-1])<k) {
                ans+=abs(k-(arr[i]+arr[i-1]));
                arr[i]=k-arr[i-1];
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++) {
            cout<<arr[i]<<" ";
        }
    }
}