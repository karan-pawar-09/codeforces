// /*
// authot:Karan
// created:09.05.2021 23:45:46
// */
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll inf=(ll)1e10;
//     string s,t;
//     cin>>s>>t;
//     int n=s.size();
//     int m=t.size();
//     vector<vector<ll>> dp(n+1,vector<ll> (m+1,inf));
//     for(int i=0;i<=n;i++) {
//         for(int j=0;j<=m;j++) {
//             if(i==0) dp[i][j]=j;
//             else if(j==0) dp[i][j]=i;
//             else if(s[i-1]==t[j-1]) {
//                 dp[i][j]=dp[i-1][j-1];
//             }            
//             else dp[i][j]=min(min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1,dp[i][j]);
            
//         }
//     }
//     cout<<dp[n][m]<<endl;
// }

/*
author:Karan
created:25.07.2021 12:36:18
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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,1e9+7));
    for(int i=1;i<=n;i++) {
        dp[i][0]=i;
    }
    for(int j=1;j<=m;j++) {
        dp[0][j]=j;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i-1]==t[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            }
            else {
                dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1,dp[i][j]});
            }
        }
    }
    cout<<dp[n][m]<<endl;
}