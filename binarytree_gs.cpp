/*
author:Karan
created:28.07.2021 13:42:39
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<int>> adj;
vector<int> value;
vector<vector<int>> arr;

void dfs(int node) {
    
    int neg=0;

    for(auto x:adj[node]) {
        if(value[x]<0) neg++;
        dfs(x);
    }
    if(adj[node].size()==0) {
        value[node]=min(arr[node][0],arr[node][1]);
    }
    else{
        if((value[adj[node][0]]<0)&&(value[adj[node][1]]<0)) {
            value[node]=min(value[adj[node][0]],value[adj[node][1]]);
        }
    }
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    arr.resize(n,vector<int> (2));
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            cin>>arr[i][j];
        }
    }

    value.resize(n,0);
    adj.resize(n);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<2;j++) {
            if(arr[i][j]>0) {
                adj[i].push_back(arr[i][j]);
            }
        }
    }
    dfs(0);
    cout<<abs(value[adj[0][0]]-value[adj[0][1]]);
}