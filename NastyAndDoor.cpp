#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        long arr[n];
        vector<long> q(n,0);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        
        for(int i=1;i<n-1;i++) {
            if((arr[i]>arr[i-1])&&(arr[i]>arr[i+1])){
                    q[i]=1;
                }
        }
    //    for(int i=0;i<n;i++) {
      //      cout<<q[i]<<" ";
        //}
      // cout<<endl;
        
        for(int i=1;i<n;i++) {
         
            q[i]+=q[i-1];
         
        }
        
        long max=q[n-2]-q[n-k];
        int tip=n-k;
        for(int l=n-k-1;l>=0;l--) {
     //       cout<<q[l+k-2]-q[l]<<" ";
            if((q[l+k-2]-q[l])>=max) {
                max=(q[l+k-2]-q[l]);
                tip=l;
            }
        }
        
         cout<<max+1<<" "<<tip+1<<endl;
    }
}