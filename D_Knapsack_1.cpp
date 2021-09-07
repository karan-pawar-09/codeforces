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
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,0)); 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=w;j++) {
            if(j>=W[i-1]) {
                dp[i][j]=max((V[i-1]+dp[i-1][j-W[i-1]]),dp[i-1][j]);
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][w]<<endl;
}