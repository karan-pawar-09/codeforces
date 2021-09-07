/*
author:Karan
created:06.06.2021 16:24:36
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const int mx=(int)1e5+7;
vector<int> arr[mx];
int visited[mx];
int in[mx];
int low[mx];
set<int> ans;
int timer;
void dfs(int node,int par=-1) {
    visited[node]=1;
    in[node]=low[node]=timer++;
    for(int child:arr[node]) {
        if(child==par) continue;
        if(visited[child]) {
            low[node]=min(low[node],in[child]);
        }
        else {
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in[node]&&par!=-1) {
                ans.insert(node);
            }      
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m;
    int a,b;
    cin>>n>>m;
    while(n&&m) {    
        ans.clear();   
        timer=0; 
        for(int i=0;i<n;i++) {
            arr[i].clear();
            visited[i]=0;
            in[i]=low[i]=0;
        }
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            arr[a-1].push_back(b-1);
            arr[b-1].push_back(a-1);
        }
        dfs(0);
        cout<<ans.size()<<endl;
        cin>>n>>m;
    }   
}