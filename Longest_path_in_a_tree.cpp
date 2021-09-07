/*
author:Karan
created:16.06.2021 23:49:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<int>> tree;
vector<bool> visited;
pair<int,int> ans;
void dfs(int node,int depth) {
    visited[node]=true;
    if(depth>ans.first) {
        ans.first=depth;
        ans.second=node;
    }
    for(auto x:tree[node]) {
        if(!visited[x]) {
            dfs(x,depth+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n; 
    tree.resize(n);
    visited.resize(n,false);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    } 
    ans={0,0};
    dfs(0,0);
    for(int i=0;i<n;i++) {
        visited[i]=false;
    }
    int node=ans.second;
    ans={0,0};
    dfs(node,0);
    cout<<ans.first<<endl;
}