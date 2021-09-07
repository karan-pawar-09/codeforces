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
    vector<ll>ans;
    for(int i=0;i<n;i++) {
        if((find(arr.begin(),arr.end(),arr[i]/2)==arr.end()||arr[i]%2)&&find(arr.begin(),arr.end(),arr[i]*3)==arr.end()) {
            ans.push_back(arr[i]);
        }
    }
    for(int i=1;i<n;i++) {
        auto it=find(arr.begin(),arr.end(),ans[i-1]*2);
        auto itr=find(arr.begin(),arr.end(),ans[i-1]/3);
       if(it!=arr.end()) {
           ans.push_back(arr[(it-arr.begin())]);
       }
        else {
            ans.push_back(arr[(itr-arr.begin())]);
        }
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
 }