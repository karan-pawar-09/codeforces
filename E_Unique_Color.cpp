#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
vector<int> p;
vector<int> ans;
vector<ll> c;
vector<bool> visited;
vector<vector<ll>> arr;
void dfs(int node) {
    visited[node]=true;
    if(p[c[node]]==0) {
        ans.push_back(node);
    }
    p[c[node]]++;
    for(auto i:arr[node]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    p[c[node]]--;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    c.resize(n);
    p.resize(1e6,0);
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }   
    arr.resize(n);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visited.resize(n,false);
    // for(int i=0;i<n;i++) {
    //     for(auto u:arr[i]) {
    //         cout<<u+1<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(0);
    sort(all(ans));
    for(int i=0;i<ans.size();i++) {        
            cout<<ans[i]+1<<endl;        
    }
}