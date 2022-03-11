/*
    author:Karan
    created:02.03.2022 20:45:00
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

const int INF = 1000000000;
vector<pair<int, int>> adj[(int)3e5+10];

void dijkstra(int s, vector<int> & d,int n) {    
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
}


void solve() {
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++) {
        adj[i].clear();
    }
    vector<int> d(n+10,INF);
    for(ll i=0;i<m;i++) {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back({b,0});
        adj[b].push_back({a,0});
    }
    for(int i=1;i<n;i++) {
        adj[i].push_back({i+1,1});
        adj[i+1].push_back({i,1});
    }
    dijkstra(1,d,n);
    
    cout<<d[n]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}