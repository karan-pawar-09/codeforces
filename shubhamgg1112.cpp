/*
author:Karan
created:18.07.2021 13:20:08
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
    vector<vector<int>> dp(5,vector<int> ((int)1e5,0));

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr),greater<int>());
    dp[0][0]=1;
    for(int i=1;i<=4;i++) {
        for(int j=0;j<n;j++) {
            for(int k=1e5-1;k>=0;k--) {
                if(arr[j]<=k) {
                    dp[i][k]+=dp[i-1][k-arr[j]];
                }
            }
        }
    }
    cout<<dp[4][0]<<endl;
}