/*
author:Karan
created:29.05.2021 12:35:58
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const int N=2e5+5;

vector<int> grid[N];
int timer;
vector<int> d[N];
int in[N],out[N];

void dfs(int u,int dep) {
    in[u]=timer++;
    d[dep].push_back(in[u]);
    for(int x:grid[u]) {
        dfs(x,dep+1);
    }
    out[u]=timer++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    timer=0;
    for(int i=2;i<=n;i++) {
        int p1;
        cin>>p1;        
        grid[p1].push_back(i);
    }
    dfs(1,0);
    int q;
    cin>>q;
    while(q--) {
        int u,D;
        cin>>u>>D;
        int ans=lower_bound(all(d[D]),out[u])-lower_bound(all(d[D]),in[u]);
        cout<<ans<<endl;
    }
}