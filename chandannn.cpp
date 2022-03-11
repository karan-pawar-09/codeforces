/*
author:Karan
created:30.06.2021 18:21:31
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 
ll n,m;
const ll mx=507;
const ll inf=(ll)1e6;
 
vector<ll> CheapestRoundTrip(ll n ,vector<vector<ll>> f) {
    ll m=f.size();
    ll arr[mx][mx];
    for(ll i=0;i<mx;i++) {
        for(ll j=0;j<mx;j++) {
            arr[i][j]=inf;
        }
    }
    for(ll i=0;i<mx;i++) {
        arr[i][i]=0;
    }
    for(ll i=0;i<m;i++) {
        arr[f[i][0]][f[i][1]]=min(arr[f[i][0]][f[i][1]],f[i][2]);
    }
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=n;j++) {
            for(ll k=0;k<=n;k++) {
                arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
        }
    } 
    multiset<ll> s;
    for(ll i=0;i<n;i++) {
        for(ll j=i+1;j<n;j++) {
            s.insert(min(arr[i][j]+arr[j][i],inf));
        }
    }
    vector<ll> anss;
    anss.push_back(*s.begin());
    s.erase(s.begin());
    anss.push_back(*s.begin());
    return anss;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout)
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> f(m,vector<ll>(3));   
    for(ll i=0;i<m;i++) {
        ll a,b,c;
        cin>>f[i][0]>>f[i][1]>>f[i][2];        
    }
    
    vector<ll> ans=CheapestRoundTrip(n,f);
    for(auto x:ans) cout<<x<<endl;
    
}