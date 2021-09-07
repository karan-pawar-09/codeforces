/*
authot:Karan
created:17.05.2021 08:31:02
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    vector<vector<double>> dp(n+1,vector<double>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            if(j==0) {
                dp[i][j]=dp[i-1][j]*(1-p[i-1]);
            }
            else {
                dp[i][j]=(dp[i-1][j-1]*p[i-1])+(dp[i-1][j]*(1-p[i-1]));
            }
        }
    }
    double ans=0;
    for(int i=(n/2)+1;i<=n;i++) {
        ans+=dp[n][i];
    }
    cout<<fixed<<setprecision(10);
    cout<<ans<<endl<<endl;  
}