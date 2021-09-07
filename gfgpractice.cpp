/*
author:Karan
created:24.07.2021 14:55:26
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    vector<int> dp(n+1,0);
    
    for(int i=0;i<n;i++) {
        int maxi=arr[i];
        dp[i]=max(arr[i],dp[i]);
        for(int j=1;j<k;j++) {
            if(i+j<n) {
                maxi=max(maxi,arr[i+j]);
                dp[i+j]=max(dp[i+j],dp[i]+maxi*(j));
            }           
        }
    }
    cout<<dp[n-1]<<endl;
}