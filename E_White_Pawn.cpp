/*
author:Karan
created:30.05.2021 21:27:13
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int aaaa=n;
    n=2*n+1;
    vector<vector<int>> grid(n,vector<int> (n,0));
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        grid[a][b]=1;
    }
    vector<vector<bool>> dp(n,vector<bool> (n,false));
    dp[0][aaaa]=true;
    for(int i=1;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(grid[i][j]==0&&dp[i-1][j]) {
                dp[i][j]=true;
            }
            if(j+1<n&&dp[i-1][j+1]&&)
        }
    }
}