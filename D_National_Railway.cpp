/*
author:Karan
created:17.07.2021 17:45:47
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=(ll)1e18+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m,c;
    cin>>n>>m>>c;
    vector<vector<ll>> arr(n,vector<ll> (m));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    ll ans=inf;
    for(int cnt=0;cnt<2;cnt++) {
        vector<vector<ll>> dp(n+1,vector<ll> (m+1,inf));
        for(ll i=1;i<=n;i++) {
            for(ll j=1;j<=m;j++) {
                dp[i][j]=min({arr[i-1][j-1],dp[i-1][j]+c,dp[i][j-1]+c});
            }
        }
        ll temp=inf;
        for(ll i=1;i<=n;i++) {
            for(ll j=1;j<=m;j++) {
                temp=min(dp[i-1][j]+c+arr[i-1][j-1],dp[i][j-1]+c+arr[i-1][j-1]);
                ans=min(ans,temp);
            }
        }
        reverse(all(arr));
    }
    cout<<ans<<endl;
}