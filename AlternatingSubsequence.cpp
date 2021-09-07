#include<bits/stdc++.h>
using namespace std;
int isPos(long i) {
    if(i>=0){
        return 1;
    }
    else{
        return 0;
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long arr[n];
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }

        bool current=isPos(arr[0]);
        long sum=arr[0];
        for(int i=1;i<n;i++) {
            
            if(isPos(arr[i])==isPos(arr[i-1])) {
                if(arr[i]>arr[i-1]){
                    
                    sum-=arr[i-1];
                    sum+=arr[i];
                }
                else{
                    sum=sum;
                }
            }
            else{
                sum+=arr[i];
            }
            cout<<sum<<endl;
        }
       // cout<<sum;
    }
}