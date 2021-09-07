#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
vector<bool> visited;
vector<bool> color;
vector<vector<int>> arr;
bool dfs(int i,bool a) {
    visited[i]=true;
    color[i]=a;
    for(int p:arr[i]) {
        if(!visited[p]) {
            if(dfs(p,!a)==false) {
                return false;
            }
        }
        else {
            if(color[i]==color[p]) {
                return false;
            }
        }
        
    }
    return true;
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    arr.resize(n);
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }
    visited.resize(n,false);
    color.resize(n,true);
    bool ans=true;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            ans=dfs(i,true);
        }
        if(ans==false) {
            break;
        }
    }
    if(ans) {
        for(int i=0;i<n;i++) {
            (color[i]==true)?cout<<"1 ":cout<<"2 ";
        }
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}