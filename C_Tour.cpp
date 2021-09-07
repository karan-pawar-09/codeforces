/*
author:Karan
created:06.06.2021 17:46:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<int>> arr;
vector<int> visited;
void dfs(int v) {
    visited[v]=1;
    for(int u:arr[v]) {
        if(!visited[u]) {
            dfs(u);
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
    arr.resize(n);
    visited.resize(n);
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        arr[a-1].push_back(b-1);
    }
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            visited[j]=false;
        }
        dfs(i);
        for(int j=0;j<n;j++) {
            if(visited[j]) {
                s.insert({i,j});
            }
        }
    }
    cout<<s.size()<<endl;
}