/*
author:Karan
created:01.08.2021 12:31:01
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n, l;
vector<vector<ll>> adj;
 
ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;
 
void dfs(ll v, ll p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (ll u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}
 
bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
ll lca(ll u, ll v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (ll i = l; i >= 0; --i) {
        if ((up[u][i]!=-1)&&(!is_ancestor(up[u][i], v)))
            u = up[u][i];
    }
    return up[u][0];
}
 
void preprocess(ll root) {
    tin.resize(n+1);
    tout.resize(n+1); //remainder to resize adj to size(n+1) and clearing up;
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<ll>(l + 1,-1));
    dfs(root, -1);
    for(ll j=1;j<=l;j++) {
        for(ll i=1;i<=n;i++) {
            if(up[i][j-1]!=-1) {
                ll par=up[i][j-1];
                up[i][j]=up[par][j-1];
            }
        }
    }
}

void solve(ll t) {
    cin>>n;
    ll m,child;
    adj.resize(n+1);
    for(ll i=0;i<=n;i++) {
        adj[i].clear();
    }
    for(ll i=1;i<=n;i++) {
        cin>>m;
        for(ll j=0;j<m;j++) {
            cin>>child;
            adj[i].push_back(child);
            adj[child].push_back(i);
        }
    }
    preprocess(1);
    ll q;
    cin>>q;
    cout<<"Case "<<t<<":"<<endl;
    while(q--) {
        ll u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t,pp;
    cin>>t;
    pp=t;
    while(t--) {
        solve(pp-t);
    }
}