/*
author:Karan
created:21.06.2021 22:42:07
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
    ll n,m;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>m;
    vector<ll> b(m);
    for(ll i=0;i<m;i++) {
        cin>>b[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,0));
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}