/*
author:Karan
created:12.08.2021 13:24:13
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll h,w;
    cin>>h>>w;

    vector<vector<char>> arr(h,vector<char> (w));
    for(ll i=0;i<h;i++) {
        for(ll j=0;j<w;j++) {
            cin>>arr[i][j];
        }
    }

    vector<pair<ll,ll>> change={
        {2,-1},{2,0},{2,1},
        {1,-2},{1,-1},{1,0},{1,1},{1,2},
        {0,-2},{0,-1},{0,1},{0,2},
        {-1,-2},{-1,-1},{-1,0},{-1,1},{-1,2},
        {-2,-1},{-2,0},{-2,1}
    };

    vector<vector<ll>> dist(h,vector<ll> (w,1e9+7));
    dist[0][0]=0;
    priority_queue<vector<ll>> pq;
    pq.push({0,0,0});
    while(pq.size()) {
        ll i=pq.top()[1];
        ll j=pq.top()[2];
        ll d=pq.top()[0];
        pq.pop();
        if(dist[i][j]!=-d) continue;
        for(auto x:change) {
            ll ni=i+x.first;
            ll nj=j+x.second;
            if(ni<0||ni>=h||nj<0||nj>=w) {
                continue;
            }
            ll cost=(arr[i][j]=='.' and (abs(i-ni)+abs(j-nj)<=1))?0:1;
            if(dist[i][j]+cost<dist[ni][nj]) {
                dist[ni][nj]=dist[i][j]+cost;
                pq.push({-dist[ni][nj],ni,nj});
            }
        }
    }
    
    cout<<dist[h-1][w-1]<<endl;
}