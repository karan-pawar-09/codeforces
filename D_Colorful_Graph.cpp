/*
author:Karan
created:25.06.2021 16:52:41
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=(ll)1e5+7;
vector<ll> grid[mx];
bool visited[mx];
set<ll> s[mx];
ll arr[mx];

void dfs(ll node) {
    visited[node]=true;
    for(ll x:grid[node]) {
        if(!visited[x]) {
            dfs(x);
            if(arr[node]!=arr[x]) {
                s[arr[x]].insert(arr[node]);
                s[arr[node]].insert(arr[x]);
            }
        }
        else {
            if(arr[node]!=arr[x]) {
                s[arr[x]].insert(arr[node]);
                s[arr[node]].insert(arr[x]);
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); m   
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m,a,b;
    cin>>n>>m;
    ll ans=(ll)(1e18+7);
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
        ans=min(ans,arr[i]);
    }
    while(m--) {
        cin>>a>>b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    for(ll i=1;i<=n;i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
 
    for(ll i=1;i<mx;i++) {
        if(s[i].size()>s[ans].size()) {
            ans=i;
        }       
    }
    cout<<ans<<endl;
}