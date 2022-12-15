/*
    author:Karan
    created:23.11.2022 04:06:21
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
ll n,a, b;
vector<ll> graph[mx];
map<pair<ll, ll>, ll> M;
set<ll> s;

void dfs1(ll u, ll par, ll x) {
    if(u == b) return;
    s.insert(x);
    for(auto e: graph[u]) {
        ll v = e, w = M[{min(e, u), max(e, u)}];
        if(v == par) continue;
        dfs1(v, u, x ^ w);
    }
}

bool dfs2(ll u, ll par, ll x) {
    if(u != b && s.count(x)) return true;
    for(auto e: graph[u]) {
        ll v = e, w = M[{min(e, u), max(e, u)}];
        if(v == par) continue;
        if(dfs2(v, u, w ^ x)) return true;
    } 
    return false;
}

void solve() {
    M.clear();
    s.clear();
    cin>>n>>a>>b;
    for(ll i=0;i<=n;i++) {
        graph[i].clear();
    }
    M[{-1, b}] = 0;
    M[{-1, a}] = 0;
    for(ll i=0;i<n-1;i++) {
        ll a, b, c;
        cin>>a>>b>>c;
        if(a> b) {
            swap(a, b);
        }
        M[{a, b}] = c;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(a, -1, 0);
    if(dfs2(b, -1, 0)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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






