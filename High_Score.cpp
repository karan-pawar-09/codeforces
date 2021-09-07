/*
author:Karan
created:10.07.2021 11:42:44
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll inf=(ll)1e18+7;

struct Tunnel {
    ll room1;
    ll room2;
    ll dist;
};

void dfs(vector<vector<ll>> &arr,vector<bool> &vis,ll node) {
    vis[node]=true;
    for(auto x:arr[node]) {
        if(!vis[x]) {
            dfs(arr,vis,x);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<Tunnel> arr(m);
    vector<vector<ll>> adjstart(n+1);
    vector<vector<ll>> adjend(n+1);
    vector<ll> d(n+1,inf);
    vector<bool> visstart(n+1,false);
    vector<bool> visend(n+1,false);

    for(ll i=0;i<m;i++) {
        cin>>arr[i].room1>>arr[i].room2>>arr[i].dist;
        adjstart[arr[i].room1].push_back(arr[i].room2);
        adjend[arr[i].room2].push_back(arr[i].room1);
        arr[i].dist=-arr[i].dist;
    }

    dfs(adjstart,visstart,1);
    dfs(adjend,visend,n);

    d[1]=0;
    bool ans=false;
    
    for(ll j=0;j<n;j++) {
        bool isChanging=false;
        for(ll i=0;i<m;i++) {
            if(d[arr[i].room1]<inf) {
                if(d[arr[i].room2]>d[arr[i].room1]+arr[i].dist) {
                    d[arr[i].room2]=d[arr[i].room1]+arr[i].dist;
                    if(j==n-1) {
                        if(visstart[arr[i].room1] and visend[arr[i].room2]) {
                            ans=true;
                        }
                    }
                    isChanging=true;
                }
            }
        }
        if(!isChanging) {
            break;
        }
    }

    if(ans) cout<<-1<<endl;
    else cout<<-1*d[n]<<endl;
}