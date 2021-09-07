/*
author:Karan
created:03.08.2021 11:59:27
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=5007;
const int mod=998244353;

vector<int> adj[mx];
int dp[mx];

int n,m,k;

void dfs(int node,int no,int par) {
    if(no>k) return;
    if(no==k) {
        if(node==1) {
            dp[node]+=dp[par];
            dp[node]%=mod;
        }
    }
    else {
        dp[node]+=dp[par];
        dp[node]%=mod;
    }
    for(auto x:adj[node]) {
        if(x==par) continue;
        dfs(x,no+1,node);
    }
        
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    cin>>n>>m>>k;
    for(int i=0;i<=n;i++) {
        dp[i]=0;
    }
    dp[0]=1;
    set<pair<int,int>> s;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(i!=j)
                s.insert({i,j});
        }
    }
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        s.erase({a,b});
    }
    for(auto x:s) {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }
    dfs(1,1,0);
    cout<<dp[1]<<endl;
}