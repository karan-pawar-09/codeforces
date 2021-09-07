/*
author:Karan
created:02.09.2021 21:08:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll infinity=1e18+7;
const ll mx=2e4+7;
ll arr[mx][1007];
ll k;

void dijkstra(ll s, vector<ll> & ans,vector<vector<ll>> &arrr) {
    ll n = k+1;
    ans.assign(n, infinity);
    ans[s] = 0;
    set<pair<ll,ll>> q;
    q.insert({0, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());  

        for(ll i=1;i<=k;i++) {
            ll dist=infinity;  
            for (auto edge : arrr[v]) {             
                if(arr[edge][i]!=-1) {
                    dist=min(dist,ans[v]+arr[edge][i]);   
                } 
            }                   
            if(ans[i]>dist) {
                ans[i]=dist;
                q.insert({dist,i});
            }    
        }  
        
    }    
}

void solve() {
    ll n,s;
    cin>>n>>k>>s;
    vector<int> ar(n+1);
    vector<vector<ll>> arrr(k+1);

    for(ll i=1;i<=n;i++) {
        cin>>ar[i];
        arrr[ar[i]].push_back(i);
    }

    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=k;j++) {
            cin>>arr[i][j];
        }
    }
    vector<ll> ans(k+1);
    dijkstra(ar[s],ans,arrr);
    for(ll i=1;i<=n;i++) {
        if(ans[ar[i]]>1e12) {
            cout<<-1<<" ";
        } else {
            cout<<ans[ar[i]]<<" ";
        }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    while(t--) {
        solve();
    }
}