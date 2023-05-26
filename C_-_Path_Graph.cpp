/*
    author:Karan
    created:28.01.2023 17:38:59
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

bool ans;
void dfs(int node, int par, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[node] = true;
    for(auto x: graph[node]) {
        if(!visited[x]) {
            dfs(x, node, visited, graph);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    ans = true;
    vector<bool> visited(n+1, false);
    vector<pair<int, int>> arr(m);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        if(a>b) {
            swap(a, b);
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
        arr[i].first = a;
        arr[i].second = b;
    }
    if(m != n-1) {
        ans = false;
    }
    dfs(1, 0, visited, graph);
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ans = false;
        }
    }
    ans? cout<<"Yes"<<endl:cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}