#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    vector<int>b(m);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<m;i++) {
        cin>>b[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++) {
        dp[i][0]=i;
    }
    for(int i=0;i<=m;i++) {
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=min({(1+dp[i][j-1]),(1+dp[i-1][j]),(dp[i-1][j-1]+(a[i-1]!=b[j-1]))});
        }
    }
     for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dp[n][m]<<endl;  
}