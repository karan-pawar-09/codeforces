/*
    author:Karan
    created:07.11.2021 18:47:26
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

const ll mod=998244353;
const ll mx=1e6+10;
vector<ll> arr[mx];
vector<ll> parent;
vector<bool> visited;
vector<char> color;
ll cycle_start, cycle_end;
ll n;
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
bool dfs(ll v, ll par) { // passing vertex and its parent vertex
    visited[v] = true;
    for (ll u : arr[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (visited[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parent[u] = v;
        if (dfs(u, parent[u]))
            return true;
    }
    return false;
}
void solve() {
    ll m;
    cin>>n>>m;
    for(ll i=0;i<=n;i++) {
        arr[i].clear();
    }
    DSU dsu(n+1);
    for(ll i=0;i<m;i++) {
        ll a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(b);
        dsu.merge(a,b);
    }
    set<ll> s;
    for(ll i=1;i<=n;i++) {
        s.insert(dsu.find(i));
    }
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;
    ll k=1;
    for(auto x:s) {
        if(dfs(x,-1) and (dsu.magnitude[x]>2)) {
            k*=2;
            k%=mod;
        }
        else {
            k*=0;
        }
    }
    cout<<k<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}