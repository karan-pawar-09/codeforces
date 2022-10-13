/*
    author:Karan
    created:21.08.2022 17:03:21
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

const int mx = 2e5+10;
const int inf = 1e9+10;
vector<int> arr[mx];
int dp[mx][2];
int ans;
void dfs(int node, int par) {
    dp[node][0] = dp[par][1] + 1;
    dp[node][1] = dp[par][0]; 
    bool leaf = true;
    int nochilds = 0;
    int childs = 0;
    for(auto child : arr[node]) {
        if(child != par) {
            leaf = false;
            dfs(child, node);
            nochilds += min(dp[child][0], dp[child][1]);
            childs += dp[child][0];
        }
    }
    dp[node][0] = nochilds+1;
    dp[node][1] = childs;
    if(leaf) {
        dp[node][0] = 1;
        dp[node][1] = 0;
    }
}

void solve() {
    int n, u, v;
    cin>>n;
    ans = inf;
    for(int i=0;i<=n;i++) {
        arr[i].clear();
        dp[i][0]=inf;
        dp[i][1]=inf;
    }
    dp[0][0]=0;
    dp[0][1]=0;
    for(int i=0;i<n-1;i++) {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    dfs(1, 0);
    cout<<min(dp[1][0], dp[1][1])<<endl;
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