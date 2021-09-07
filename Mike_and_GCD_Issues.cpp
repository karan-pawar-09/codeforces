#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++) {
        cin>>arr[i];
    }
    long long right;
    long long left;    
     for(long long i=0;i<n;i++) {
        bool flag=false;
        long long ans;
        left=-INT_MAX;
        right=INT_MAX;
        for(long long j=i+1;j<n;j++) {
            if(__gcd(arr[i],arr[j])!=1) {
                flag=true;
                right=j+1;
                break;
            }
        }
        for(long long j=i-1;j>=0;j--) {
            if(__gcd(arr[i],arr[j])!=1) {
                flag=true;
                left=j+1;
                break;
            }
            
        }        
        
        if(flag==true) {
            abs(i-left)<abs(right-i)?ans=left:ans=right;
        }
        else{            
            ans=-1;
        }
        cout<<ans<<" ";
   }
}