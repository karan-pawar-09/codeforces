/*
    author:Karan
    created:09.06.2023 21:40:13
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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> adj(n+1);
    vector<ll> X(k), D(k);
    for(ll i = 0; i < k; i++) {
        cin >> X[i];
    }
    for(ll j = 0; j < k; j++) {
        cin >> D[j];
    }
    for(ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS
    queue<pair<ll, ll>> q;
    vector<ll> used(n+1, 0);
    for(ll i = 0; i < k ;i++) {
        q.push({X[i], D[i]});
        used[X[i]] = D[i];
    }
    while(!q.empty()) {
        pair<ll, ll> v = q.front();
        q.pop();
        for(ll u: adj[v.first]) {
            if(v.second-1 > 0 && v.second - 1 > used[u]) {
                used[u] = v.second - 1;
                q.push({u, used[u]});
            }
        }
    }

    for(ll i = 1; i <= n; i++) {
        if(used[i] <= 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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