/*
    author:Karan
    created:11.09.2021 10:40:57
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool comp(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b) {
    return((a.second.first*b.second.second)>(b.second.first*a.second.second));
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> cost(n),nutrients(n),min_quantity(n),max_quantity(n);
    ll m;
    for(ll i=0;i<n;i++) cin>>cost[i];
    cin>>n;
    for(ll i=0;i<n;i++) cin>>nutrients[i];
    cin>>n;
    for(ll i=0;i<n;i++) cin>>min_quantity[i];
    cin>>n;
    for(ll i=0;i<n;i++) cin>>max_quantity[i];
    cin>>m;
    ll money=0;
    ll ans=0;
    for(ll i=0;i<n;i++) {
        money+=min_quantity[i]*cost[i];
        ans+=nutrients[i]*min_quantity[i];
        max_quantity[i]-=min_quantity[i];
    }
    vector<pair<ll,pair<ll,ll>>> arr(n);
    for(ll i=0;i<n;i++) {
        arr[i].first=max_quantity[i];
        arr[i].second.first=nutrients[i];
        arr[i].second.second=cost[i];
    }
    sort(all(arr),comp);
    ll mon=m-money;
    for(ll i=0;i<n && mon>0;i++) {
        ll temp=mon/arr[i].second.second;
        temp=min(temp,arr[i].first);
        mon-=temp*arr[i].second.second;
        ans+=temp*arr[i].second.first;
    }
    if(money>m) {
        cout<<0<<endl;
    }
    else
        cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);    
    solve();    
}