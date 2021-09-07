/*
author:Karan
created:26.07.2021 10:09:48
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
    int n;
    cin>>n;
    vector<int> arr(n);
    int x=0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        x+=arr[i];
    }
    vector<bool> dp(x+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++) {
        for(int j=x;j>=1;j--) {
            if(j-arr[i]>=0) {
                dp[j]=dp[j]|dp[j-arr[i]];
            }
        }
    }
    for(int i=0;i<=x;i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    double a=0; 
    double b=0;
    for(int i=1;i<x;i++) {
        
        if(dp[i]) {
            a+=abs(x-2*i);
            b++;
        }
        
    }
    
    cout<<a/b<<endl;
}