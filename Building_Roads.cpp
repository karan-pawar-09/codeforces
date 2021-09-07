#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
vector<bool> visited;
vector<vector<ll>> arr;
void dfs(ll u) {
    visited[u]=true;
    for(auto v:arr[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,a,b;
    cin>>n>>m;
    arr.resize(n);
    for(ll i=0;i<m;i++) {
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    visited.resize(n,false);
    vector<ll> init;
    ll ans=0;
    for(ll i=0;i<n;i++) {
        if(!visited[i]) {
            ans++;
            init.push_back(i+1);
            dfs(i);
        }
    }
    cout<<ans-1<<endl;
    for(ll i=0;i<ans-1;i++) {
        cout<<init[i]<<" "<<init[i+1]<<endl;
    }
}