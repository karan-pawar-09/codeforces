/*
    author:Karan
    created:05.02.2022 18:22:12
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

const int mx=2e6+10;
vector<int> arr[mx];
bool visited[mx];

void dfs(int node) {
    visited[node]=true;
    for(auto x:arr[node]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=0;i<=n;i++) {
        arr[i].clear();
        visited[i]=false;
    }
    int a,b;
    vector<int> extra;
    while(q--) {
        cin>>a>>b;
        a--;
        if(a!=b) {
            arr[a].push_back(b);
            arr[b].push_back(a);
        } else {
            arr[a-1].push_back(a);
        }
    }
    dfs(0);
    if(visited[n]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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