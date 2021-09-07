#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<ll>> arr;
vector<bool> visited;
vector<int> indegree;
vector<int> dist;
int ans;
void dfs(int node) {
    visited[node]=true;
    for(int u:arr[node])  {
        indegree[u]--;
        dist[u]=max(dist[u],dist[node]+1);
        if(indegree[u]==0) {
            dfs(u);
        }
    }    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    arr.resize(n);
    visited.resize(n);
    indegree.resize(n,0);
    dist.resize(n,0);
    ans=0;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        indegree[b]++;
    }
    for(int i=0;i<n;i++) {
        if(!visited[i]&&indegree[i]==0) {
            dfs(i);
        }
    }
    for(int i=0;i<n;i++) {
        ans=max(ans,dist[i]);
    }
    cout<<ans<<endl;
}