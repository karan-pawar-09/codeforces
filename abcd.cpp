/*
	author:Karan
	created:20.09.2022 15:26:10
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

const ll mx = 5e5+10;
ll n, l;
vector<ll> adj[mx];
map<pair<ll,ll>, ll> M;
ll timer;
vector<ll> tin, tout;
vector<vector<ll>> up;

ll dist[mx];
 
void dfs(ll v, ll p) {
	dist[v] = dist[p] + M[{min(v, p), max(v, p)}];
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
	dfs(root, 0);
	for(ll j=1;j<=l;j++) {
		for(ll i=1;i<=n;i++) {
			if(up[i][j-1]!=-1) {
				ll par=up[i][j-1];
				up[i][j]=up[par][j-1];
			}
		}
	}
}

void process1(int M[][mx], int A[mx], int N) {
  int i, j;
  for (i = 0; i < N; i++)
    M[i][i] = i;
  for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++)
      if (A[M[i][j - 1]] < A[j])
        M[i][j] = M[i][j - 1];
      else
        M[i][j] = j;
}

void solve() {
	cin>>n;
	tin.clear();
	tout.clear();
	M.clear();
	for(ll i=0;i<=n;i++) {
		adj[i].clear();
		dist[i] = 0;
	}
	for(ll i=0;i<n-1;i++) {
		ll a, b, c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		M[{min(a, b), max(a, b)}] = c;
	}
	ll x,y,z;
	cin>>x>>y>>z;
	preprocess(1);
	ll res = 1e18+10;
	ll city = 0;
	for(ll i=1;i<=n;i++) {
		ll lcaPX = lca(i, x);
		ll lcaPY = lca(i, y);
		ll lcaPZ = lca(i, z);
		ll distPX = dist[i] + dist[x] - (2*dist[lcaPX]);
		ll distPY = dist[i] + dist[y] - (2*dist[lcaPY]);
		ll distPZ = dist[i] + dist[z] - (2*dist[lcaPZ]);
		if((distPX+distPY+distPZ) < res) {
			res = (distPX+distPY+distPZ);
			city = i;
		}
	}
	cout<<city<<endl;
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