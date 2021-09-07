/*
author:Karan
created:11.08.2021 18:10:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=2e5+7;

vector<ll> arr[mx];

vector<bool> visited;
void dfs(ll node) {
    visited[node]=true;
    bool doublevisit=false;
    for(auto x:arr[node]) {
        if(!visited[x]) {
            cout<<node<<" ";
            dfs(x);
            doublevisit=true;
        }
    }
    cout<<node<<" ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll a,b;
    visited.resize(n+7,false);
    for(ll i=0;i<n-1;i++) {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(ll i=0;i<=n;i++) {
        sort(all(arr[i]));
    }
    dfs(1);
}