/*
    author:Karan
    created:06.01.2022 23:10:01
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

const int mx=3e5+7;
vector<int> G[mx],adj[mx];
vector<int> parent,dist,roott;
vector<bool> visited;
set<int> s;
int cycle_start, cycle_end,n,l,timer;
vector<int> tin, tout;
vector<vector<int>> up;

bool dfs_cycle(int v, int par) { 
    visited[v] = true;
    for (int u : G[v]) {
        if(u == par) continue; 
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs_cycle(u, parent[u]))
            return true;
    }
    return false;
}

void dfs_primary(int v, int par) {
    if(par!=0) {
        roott[v]=roott[par];
    }
    dist[v]=dist[par]+1;
    for(auto u:adj[v]) {
        if(u!=par) {
            dfs_primary(u,v);
        }
    }
}

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void solve() {
    int q;
    cin>>n>>q;
    vector<pair<int,int>> arr(n);


    //---------------- Clear Everything ------------//
    s.clear();
    parent.clear();
    visited.clear();
    dist.clear();
    tin.clear();
    tout.clear();
    for(int i=0;i<=n;i++) {
        G[i].clear();
        adj[i].clear();
    }


    //---------------- Input -----------------------//
    
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
        G[arr[i].first].push_back(arr[i].second);
        G[arr[i].second].push_back(arr[i].first);
    }


    //---------------- Cycle Vertices --------------//

    visited.assign(n+10, false);
    parent.assign(n+10, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dfs_cycle(v, parent[v]))
            break;
    }
    s.insert(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = parent[v]) {
        s.insert(v);
    }

    
    //----------- Creating New Graph -------------//
    for(int i=0;i<n;i++) {
        if(s.find(arr[i].first)!=s.end() and s.find(arr[i].second)!=s.end()) {

        } else {
            adj[arr[i].first].push_back(arr[i].second);
            adj[arr[i].second].push_back(arr[i].first);
        }
    }


    //-------- Deciding root for each element ---//
    dist.resize(n+10,0);
    dist[0]=-1;
    roott.resize(n+10,0);
    for(auto x:s) {
        roott[x]=x;
        dfs_primary(x,0);
    }

    
    //-------- LCA calculation ------------------//
    l = ceil(log2(n+2));
    tin.resize(n+10);
    tout.resize(n+10);
    timer = 0;
    up.clear();
    up.assign(n+10, vector<int>(l + 10));

    for(auto x:s) {
        dfs(x,x);
    }    


    //-------------- Queries---------------------//
    for(int i=0;i<q;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        if(roott[a]==roott[b]) {            
            {
                int p=lca(a,b);
                if(s.find(p)!=s.end()) {
                    int d1=dist[a];
                    int d2=dist[b];
                    int ring=s.size();            
                    int rem=n-d1-d2-ring;
                    c-=rem;
                    c=max(c,0);
                    int x=min(c,ring);
                    c-=x;
                    c*=2;            
                    cout<<c+x<<endl;
                } else {
                    int res=abs(dist[a]+dist[b])-2*dist[p];
                    int rem=n-res;
                    c-=rem;
                    c=max(0,c);
                    cout<<c<<endl;
                }                
            }            
        } else {
            int d1=dist[a];
            int d2=dist[b];
            int ring=s.size();            
            int rem=n-d1-d2-ring;
            c-=rem;
            c=max(c,0);
            int x=min(c,ring);
            c-=x;
            c*=2;            
            cout<<c+x<<endl;
        }        
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}