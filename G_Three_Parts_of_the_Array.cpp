#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    ll ans=0;
    ll sum_start=arr[start];
    ll sum_end=arr[end];
    while(start<end) {
        if(sum_start==sum_end) {    
            ans=max(ans,sum_start);
        }
        if(sum_start<sum_end) {
            start++;
            if(start!=end) {
                sum_start+=arr[start];
            }
                
        }
        else {
            end--;
            if(start!=end) {
                sum_end+=arr[end];
            }
            
        }
    }
    cout<<ans<<endl;
}