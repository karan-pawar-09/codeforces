/*
authot:Karan
created:17.05.2021 17:46:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<ll>> dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b;
    cin>>a>>b;
    dp.resize(a+1,vector<ll>(b+1,(int)1e9+7));
    for(int i=0;i<=min(a,b);i++) {
        dp[i][i]=0;
    }
    for(int i=1;i<=a;i++) {
        for(int j=1;j<=b;j++) {
            for(int k=1;k<i;k++) {
                dp[i][j]=min(dp[i][j],dp[i-k][j]+dp[k][j]+1);
            }
            for(int k=1;k<j;k++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
}