/*
author:Karan
created:05.06.2021 20:29:59
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll price;
    cin>>price;
    ll a,b;
    cin>>a>>b;
    vector<vector<ll>> adj(n);
    vector<vector<ll>> arr(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }    
    vector<bool> used(n,false);
    vector<ll> d(n), p(n);
    queue<ll> q;
    ll s=a;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    if (!used[b]) {
        cout <<0<<endl;;
    } else {
        vector<ll> path;
        for (ll v = b; v != -1; v = p[v])
            path.push_back(v);
        cout<<(path.size()-1)*price<<endl;
    }
}