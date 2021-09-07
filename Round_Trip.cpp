#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<ll>> arr;
vector<ll> parent;
vector<bool> visited;
ll ans;
ll endis;
bool dfs(int i,int p) {
    visited[i]=true;
    parent[i]=p;
    for(auto v:arr[i]) {
        if(!visited[v]) {
            if(dfs(v,i)==true) {
                return true;
            }
        }
        else {
            if(parent[v]!=i&&v!=p) {
                ans=i;
                endis=v;
                return true;                
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    arr.resize(n);
    parent.resize(n,-1);
    visited.resize(n,false);
    for(int i=0;i<m;i++) {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[b].push_back(a);
        arr[a].push_back(b);
    }
    bool answer=false;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(dfs(i,-1)==true) {
                answer=true;
                break;
            }
        }
    }
    if(answer)  {
        vector<ll> final;
        for(int i=ans;i!=endis;i=parent[i]) {
            final.push_back(i+1);            
        }
        final.push_back(endis+1);
        final.push_back(ans+1);
        cout<<final.size()<<endl;
        for(int i=0;i<final.size();i++) {
            cout<<final[i]<<" ";
        }
        cout<<endl;
     }
     else {
         cout<<"IMPOSSIBLE"<<endl;
     }
}