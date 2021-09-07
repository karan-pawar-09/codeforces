/*
authot:Karan
created:17.05.2021 11:32:23
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
vector<vector<int>> arr;
vector<int> visited;
vector<int> node;
bool cycle;
void dfs(int i,int value) {
    if(cycle) return ; 
    visited[i] = 1 ; 
    node[i]=value;
    for(int u:arr[i]) {
        if(visited[u]==1) cycle=true;
        if(visited[u]==0) {
            dfs(u,value-1);
        }
    }
    visited[i]=2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        node.clear();
        visited.clear();
        arr.clear();
        node.resize(n,1);
        visited.resize(n,false);
        arr.resize(n);
        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            arr[a].push_back(b);
        }
        cycle = false ;
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                dfs(i,n);
            }
        }
        if(cycle) {
            cout << "NO"<<endl ; 
        }
        else {
            cout << "YES"<<endl ; 
 
        for(int i = 0 ; i < n ; ++i) {
            cout << node[i] << " " ; 
        }
 
        cout << endl; 
        }
    }
}
