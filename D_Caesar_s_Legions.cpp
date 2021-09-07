/*
author:Karan
created:25.06.2021 15:28:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int n1,n2,k1,k2;
int dp[110][110][11][11];
const int mod=(int)1e8;

int ans(int n,int m,int k,int p) {
    if(n+m==0) return 1;
    if(dp[n][m][k][p]!=-1) return dp[n][m][k][p];
    int x=0;
    int y=0;
    if(n>0&&k>0) x=ans(n-1,m,k-1,k2)%mod;
    if(m>0&&p>0) y=ans(n,m-1,k1,p-1)%mod;
    dp[n][m][k][p]=(x%mod+y%mod)%mod;
    return dp[n][m][k][p];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin>>n1>>n2>>k1>>k2;
    for(int i=0;i<110;i++) {
        for(int j=0;j<110;j++) {
            for(int k=0;k<11;k++) {
                for(int l=0;l<11;l++) {
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
    cout<<ans(n1,n2,k1,k2)<<endl;
}