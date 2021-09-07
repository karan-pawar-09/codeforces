/*
author:Karan
created:13.06.2021 15:25:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int l,n;
        cin>>n>>l;
        int dp[n+1][l+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=l;j++) {
                dp[i][j]=0;
            }
        }
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(all(arr));
        for(int i=1;i<=n;i++) {
            dp[i][arr[i-1].first+arr[i-1].second]=1;
            bool k=false;
            for(int j=1;j<=l;j++) {                
                if(j>=arr[i-1].first+arr[i-1].second&&!k) {
                    dp[i][j]=max(dp[i][j],dp[i][j-arr[i-1].second]+dp[i-1][j]);
                    k=true;
                }
                dp[i][j]=max({dp[i][j-1],dp[i-1][j],dp[i][j]});
            }
        }
        cout<<dp[n][l]<<endl;
    }   
}