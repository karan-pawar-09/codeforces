/*
author:Karan
created:10.07.2021 18:07:04
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=1e5+7;

vector<ll> arr[mx];
bool used[mx];
ll d[mx];

void bfs() {
    queue<ll> q;
    q.push(1);
    used[1]=true;
    while(q.size()) {
      ll v = q.front();
        q.pop();
        for (ll u : arr[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
            }
        }  
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,q;
    cin>>n>>q;
    for(ll i=0;i<=n+1;i++) {
        arr[i].clear();
        used[i]=false;
        d[i]=0;
    }
    for(ll i=0;i<n-1;i++) {
        ll a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs();
    while(q--) {
        ll a,b;
        cin>>a>>b;
        ll dist=d[a]+d[b];
        if(dist%2) {
            cout<<"Road"<<endl;
        }
        else {
            cout<<"Town"<<endl;
        }
    }
}