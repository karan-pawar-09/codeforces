#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,w;
    cin>>n>>w;
    vector<ll> W(n);
    vector<ll>V(n);
    for(int i=0;i<n;i++) {
        cin>>W[i]>>V[i];
    }
    ll value=(ll)1e5;
    ll infinity=(ll)1e18;
    vector<vector<ll>> dp(n+1,vector<ll>(value+1,infinity)); 
    for(int i=0;i<=n;i++) {
        dp[i][0]=0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=value;j++) {
            if(j>=V[i-1]) {
                dp[i][j]=min((W[i-1]+dp[i-1][j-V[i-1]]),dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
   ll ans=0;
   for(int i=value;i>=0;i--) {
       if(dp[n][i]<=w) {
           ans=i;
           break;
       }
   }

cout<<ans<<endl;
}