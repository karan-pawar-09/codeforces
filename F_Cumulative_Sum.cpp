/*
author:Karan
created:04.07.2021 18:23:56
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
    ll n=10;
    ll m=10;
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
    for(ll i=0;i<=n;i++) {
        dp[i][0]=i*i;
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=m;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
