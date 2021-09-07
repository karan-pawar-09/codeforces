/*
author:Karan
created:07.08.2021 18:12:39
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
    int r,g,t;
    cin>>r>>g>>t;
    int sum=max({r,g,t});
    vector<vector<int>> dp(sum+1,vector<int> (3,0));
   
    if(r>0) {
        dp[0][0]=1;
        r--;
    }
    if(g>0) {
        dp[0][1]=1;
        g--;
    }
    if(t>0) {
        dp[0][2]=1;
        t--;
    }
    for(int i=1;i<=sum;i++) {
        if(r>=0) {
            dp[i][0]=dp[i-1][1]+dp[i-1][2];
            r--;
        }
        if(g>=0) {
            dp[i][1]=dp[i-1][0]+dp[i-1][2];
            g--;
        }
        if(t>=0) {
            dp[i][2]=dp[i-1][1]+dp[i-1][0];
            t--;
        }
    }
    cout<<max({dp[sum][1],dp[sum][2],dp[sum][0]});
}