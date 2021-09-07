/*
author:Karan
created:26.07.2021 16:38:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,m,a,b;
    cin>>n>>m;
    vector<vector<int>> arr(n+1);
    for(int i=0;i<m;i++) {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vector<int> mini(n+1,1e9);
    vector<bool> visited(n+1,false);
    vector<int> value(n+1,0);
    value[1]=1;
    visited[1]=true;
    queue<pair<int,int>> q;
    q.push({1,0});
    while(q.size()) {
        pair<int,int> node=q.front();
        q.pop();
        for(auto x:arr[node.first]) {
            if(!visited[x]) {
                q.push({x,node.second+1});
            }
            if(mini[x]>node.second+1) {
                mini[x]=node.second+1;
                value[x]=(value[x]%mod+value[node.first]%mod)%mod;
            }
            else if(mini[x]==node.second+1) {
                value[x]=(value[x]%mod+value[node.first]%mod)%mod;
            }
            visited[x]=true;
        }
    }
    cout<<value[n]%mod<<endl;
}