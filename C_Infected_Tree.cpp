/*
    author:Karan
    created:10.06.2022 23:41:13
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

const int mx = 3e5+10;
vector<int> arr[mx];
int dp[mx];
int childs[mx];

int dfs(int node, int par) {
    int sum=0;
    for(auto x: arr[node]) {
        if(x != par) {
            sum += dfs(x, node);
            dp[node] = max(dp[node],dp[x]+childs[x]-1);
        }
    }
    childs[node]=sum;
    return childs[node]+1;
}

void solve() {
    int n,u,v;
    cin>>n;
    for(int i = 0; i <= n; i++) {
        arr[i].clear();
        dp[i]=0;
        childs[i]=0;
    }
    for(int i = 0; i<n-1; i++) {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1,-1);
    cout<<dp[1]<<endl;
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