/*
    author:Karan
    created:25.06.2022 22:38:45
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mx = 2e5+10;
vector<int> arr[mx];
set<pair<int,int>> specialedges;
bool visited[mx];
int tin[mx], low[mx];
int timer;

struct DSU {
    vector<ll> parent;
    vector<ll> magnitude;
    DSU(ll n) {
        parent.resize(n+1);
        magnitude.resize(n+1);
        for(ll i=1;i<=n;i++) {
            make_set(i);
        }
    }

    ll find(ll v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }

    void make_set(ll v) {
        parent[v] = v;
        magnitude[v] = 1;
    }

    void merge(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (magnitude[a] < magnitude[b])
                swap(a, b);
            parent[b] = a;
            magnitude[a] += magnitude[b];
        }
    }
};

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : arr[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                specialedges.insert({to,v});
            }
        }
    }
}

long long special_sol(int n, int m, vector<vector<int>> Edg) {
    timer = 0;
    specialedges.clear();
    for(int i=0;i<=n;i++) {
        arr[i].clear();
        visited[i]=false;
        tin[i]=-1;
        low[i]=-1;
    }
    DSU dsu = DSU(mx);
    for(auto x: Edg) {
        arr[x[0]].push_back(x[1]);
        arr[x[1]].push_back(x[0]);
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    for(auto x: Edg) {
        if((specialedges.find({x[0],x[1]}) == specialedges.end()) && (specialedges.find({x[1],x[0]}) == specialedges.end())) {
            dsu.merge(x[0],x[1]);
        }
    }
    long long ans=0;
    for(auto x:specialedges) {
        int a=x.first;
        int b=x.second;
        ans+=dsu.magnitude[dsu.find(a)]*dsu.magnitude[dsu.find(b)];
    }
    return ans;
}

void solve() {
    int n,m,u,v;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++) {
        cin>>u>>v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    cout<<special_sol(n,m,edges)<<endl;
    
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