/*
authot:Karan
created:16.05.2021 14:20:25
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const int mod=(ll)1e9;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=0,k;i<n;i++) {
        cin>>k;
        if(k) {
            a.push_back(i);
        }
        else {
            b.push_back(i);
        }
    }
    n=a.size();
    int m=b.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,mod));
    for(int i=0;i<=m;i++) {
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j]=min(dp[i][j-1],(dp[i-1][j-1]+abs(a[i-1]-b[j-1])));
        }
    }
    cout<<dp[n][m]<<endl;
}