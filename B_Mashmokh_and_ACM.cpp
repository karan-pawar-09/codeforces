/*
author:Karan
created:23.06.2021 12:23:09
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll MOD=(ll)1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,k;
    cin>>n>>k;
    ll dp[k+1][n+1];
    for(ll i=0;i<=k;i++) {
        for(ll j=0;j<=n;j++) {
            dp[i][j]=0;
        }
    }
    for(ll i=1;i<=n;i++) {
        dp[1][i]=1;
    }
    for(ll i=2;i<=k;i++) {
        for(ll j=1;j<=n;j++) {
            for(ll k=j;k<=n;k+=j) {
                dp[i][k]=(dp[i][k]%MOD+dp[i-1][j]%MOD)%MOD;
            }
        }
    } 
    ll ans=0;
    for(ll i=0;i<=n;i++) {
        ans=(ans%MOD+dp[k][i]%MOD)%MOD;
    }
    cout<<ans<<endl; 
}