/*
    author:Karan
    created:25.01.2022 20:27:18
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

const int mx=1e6+10;
vector<int> graph[mx];
bool visited[mx];
void dfs(int node) {
    visited[node]=true;
    for(auto x:graph[node]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) {
        graph[i].clear();
        visited[i]=false;
    }
    int k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>k;
            if(k && i!=j) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            res++;
            dfs(i);
        }
    }

    cout<<res<<endl;

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