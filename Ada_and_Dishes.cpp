#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        if(n==1) {
            cout<<arr[0]<<endl;
        }
        else{
            sort(arr.begin(),arr.end(),greater<int>());
            int ans=0;
            int rem=arr[0];
            for(int i=0;i<n-1;i++) {
                ans+=min(rem,arr[i+1]);
                rem=abs(arr[i+1]-rem);
                
            }
            cout<<ans+rem<<endl;
        }
    }
}