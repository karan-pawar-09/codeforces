/*
    author:Karan
    created:29.01.2023 12:10:03
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

const ll mx = 2e5+10;
const ll inf = 1e9+10;
bool black[mx];
bool used[mx];
ll d[mx];
ll p[mx];
ll arr[mx];
vector<ll> graph[mx];

void bfs(ll s, ll len, ll n) {
    queue<ll> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : graph[v]) {
            if (d[v]+1 < d[u] && d[v]+1 < len) {
                q.push(u);
                d[u] = d[v] + 1;
            }
           
        }
    }
    
}

void solve() {
    ll n;
    cin>>n;
    for(ll i=0;i<=n;i++) {
        black[i] = false;
        d[i] = inf;
        graph[i].clear();
    }
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(ll i=0;i<n-1;i++) {
        ll a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll mini = inf;
    for(ll i=1;i<=n;i++) {
        ll node = arr[i];
        mini = min(mini, d[node]);
        if(mini >= 2) {
            bfs(node, mini, n);
        }
        if(i>1)
            cout<<mini<<" ";
    }
    cout<<endl;
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