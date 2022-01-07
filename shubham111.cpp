/*
    author:Karan
    created:04.01.2022 19:22:43
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

vector<bool> visited;
vector<int> tin, low;
int timer;
int res;
vector<vector<int>> adj(2e6+7);

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                res++;
        }
    }
}

int countBridge(vector<vector<int>> &arr,int n) {
    timer = 0;
    res=0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(arr[i][j]==1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    return res;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int> (n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<countBridge(arr,n)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}