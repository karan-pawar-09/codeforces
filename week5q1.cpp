/*
author:Karan
created:21.06.2021 22:00:07
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> dp(n+1,1e18+7);
    dp[0]=0;
    for(ll i=1;i<=n;i++) {
        dp[i]=min(dp[i],dp[i-1]+1);
        if(i>=3) dp[i]=min(dp[i],dp[i-3]+1);
        if(i>=4) dp[i]=min(dp[i],dp[i-4]+1);
    }   
    cout<<dp[n]<<endl;
}