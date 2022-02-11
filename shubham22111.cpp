/*
    author:Karan
    created:11.02.2022 22:15:57
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    int n,m;
    cin>>n>>m;
    const int inf=1e9+7;
    vector<vector<int>> dp(n+1,vector<int> (m+1,inf));
    dp[1][1]=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(i+j<=m)
                dp[i][i+j]=min(dp[i][j+i],dp[i][j]+1);
            if(i+j<=n)
                dp[i+j][j]=min(dp[i+j][j],dp[i][j]+1);
        }   
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            (dp[i][j]!=inf)?cout<<dp[i][j]<<" ":cout<<-1<<" ";  
        }
        cout<<endl;
    }
     
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}