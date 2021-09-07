/*
author:Karan
created:24.05.2021 20:42:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void dfs(ll x,vector<vector<ll>>&adj,vector<pair<ll,ll>> &arr,vector<vector<ll>>&dp,ll parent) {

    for(ll u:adj[x]) {
        if(u!=parent) {
            dfs(u,adj,arr,dp,x);
            dp[x][0]+=max(abs(arr[x].first-arr[u].first)+dp[u][0],abs(arr[x].first-arr[u].second)+dp[u][1]);
            dp[x][1]+=max(abs(arr[x].second-arr[u].first)+dp[u][0],abs(arr[x].second-arr[u].second)+dp[u][1]);
        }        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<pair<ll,ll>> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i].first>>arr[i].second;
        }
        vector<vector<ll>> adj(n);
        for(ll i=0;i<n-1;i++) {
            ll a,b;
            cin>>a>>b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        dfs(0,adj,arr,dp,-1);
        cout<<max(dp[0][0],dp[0][1])<<endl;
    }
}