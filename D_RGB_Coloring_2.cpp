#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<ll>> arr;
vector<bool> visited;
vector<ll> value;

void dfs(ll a,ll b) {
    visited[a]=true;  
    for(ll u:arr[a]) {      
        if(b!=u) {
            value[u]--;
        } 
        if(!visited[u]) {
            dfs(u,a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    arr.resize(n);
    visited.resize(n,false);
    value.resize(n,3);
    for(ll i=0;i<m;i++) {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    ll ans=1;
   
    for(ll i=0;i<n;i++) {
       
        if(!visited[i]) {
            dfs(i,-1);
        }
        
    }
    for(int i=0;i<n;i++) {
        if(value[i]>=0) {
            ans*=value[i];
        }
        else {
            ans=0;
            break;
        }
    }
    for(int i=0;i<n;i++) {
        if(arr[i].size()>=3) {
            ans=0;
            break;
        }
    }
    cout<<ans<<endl;
}


