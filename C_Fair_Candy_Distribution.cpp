/*
author:Karan
created:04.07.2021 17:46:14
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
    ll n,k;
    cin>>n>>k;    
    vector<pair<ll,ll>> arr(n);    
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(all(arr));
    vector<ll> add(n);
    vector<ll> ans(n);
    ll answer=k/n;
    k%=n;
    for(ll i=0;i<k;i++) {
        add[i]=1;
    }
    for(ll i=0;i<n;i++) {
        ans[arr[i].second]=answer+add[i];
    }
    for(ll i=0;i<n;i++) {
        cout<<ans[i]<<endl;
    }
}