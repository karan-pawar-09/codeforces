/*
    author:Karan
    created:07.02.2023 18:07:26
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

const int mx = 1e5+10;
vector<int> graph[mx];
int dp[mx];
int parent[mx];
int cycleStart, cycleEnd;

bool dfs(int node) {
    dp[node] = 1;
    for(auto x: graph[node]) {
        if(dp[x] == 1) {
            cycleStart = x;
            cycleEnd = node;
            return true;
        } else if(dp[x] == 2) {

        } else {
            parent[x] = node;
            if(dfs(x)) {
                return true;
            }
        }
    }
    dp[node] = 2;
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cycleStart = -1;
    cycleEnd = -1;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++) {
        dp[i] = 0;
    }
    for(int i=1;i<=n;i++) {
        if(dp[i] == 0 && dfs(i)) {
            break;
        }
    }
    if(cycleEnd != -1) {
        vector<int> cycle;
        cycle.push_back(cycleStart);
        for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(cycleStart);
        reverse(all(cycle));
        cout<<cycle.size()<<endl;
        for(auto x: cycle) {
            cout<<x<<" ";
        }
        cout<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}