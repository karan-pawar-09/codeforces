/*
author:Karan
created:27.08.2021 19:03:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int ans(vector<int> arr) {
    int n=arr.size();
    sort(all(arr));
    int ans=1;
    int temp=1;
    for(int i=1;i<n;i++) {
        if(arr[i]-arr[i-1]<=1) {
            temp++;
        }
        else {
            temp=1;
        }
        ans=max(ans,temp);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<ans(arr)<<endl;
}