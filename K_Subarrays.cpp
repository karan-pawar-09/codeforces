/*
author:Karan
created:31.05.2021 21:48:57
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<vector<ll>> dp(n+1,vector<ll> (k+1,(ll)-1e18+7));
        vector<vector<ll>> pref(n+1,vector<ll> (k+1,(ll)-1e18+7));
        dp[0][0]=0;
        pref[0][0]=0;
        for(ll i=1;i<=n;i++) {
            dp[i][0]=0;
            pref[i][0]=0;
            for(ll j=1;j<=k;j++) {
                dp[i][j]=max(pref[i-1][j-1],dp[i-1][j])+j*arr[i-1];
                pref[i][j]=max({pref[i-1][j],dp[i][j],pref[i][j]});
            }
        }
        for(int i=1;i<=n;i++) {
            dp[i][k]=max(dp[i][k],dp[i-1][k]);
        }
        cout<<dp[n][k]<<endl;
    }
}