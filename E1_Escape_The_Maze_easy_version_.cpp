/*
    author:Karan
    created:26.11.2021 10:05:47
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

const ll mx=2e5+10;
const ll inf=1e9+7;
ll time_[mx];
bool used[mx];
vector<ll> adj[mx];
bool ans;

void dfs(ll node,ll par,ll t) {
    ll k=0;
    if(t>=time_[node]) {
        return;
    }
    for(auto x:adj[node]) {
        k++;
        if(x!=par) {            
            dfs(x,node,t+1);
        }
    }
    if(k==1 and node!=1) {
        ans=true;
        return;
    }
}

void solve() {
    ans=false;
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<=n;i++) {
        time_[i]=inf;
        used[i]=false;
        adj[i].clear();
    }
    queue<ll> q;
    for(ll i=0;i<k;i++) {
        ll a;
        cin>>a;
        used[a]=true;
        time_[a]=0;
        q.push(a);
    }
    for(ll i=0;i<n-1;i++) {
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while(q.size()) {
        ll v=q.front();
        q.pop();
        for(auto x:adj[v]) {
            if(!used[x]) {
                used[x]=true;
                q.push(x);
                time_[x]=time_[v]+1;
            }
        }
    }
    dfs(1,-1,0);
    if(ans) cout<<"YES"<<endl;
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