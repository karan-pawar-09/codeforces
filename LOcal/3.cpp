#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    arr[n]=INT_MAX;
    vector<int> ans;
    for(int i=1;i<n;i++){
      
        if(arr[i-1]<arr[i]&&arr[i+1]<arr[i]) {
            ans.push_back(max(arr[i-1],arr[i+1]));
        }
        else{
            ans.push_back(min(arr[i-1],arr[i]));
        }
    }
    sort(ans.begin(),ans.end());
    long ap=ans.size();
    cout<<ans[ap-1]+ans[ap-2];
}