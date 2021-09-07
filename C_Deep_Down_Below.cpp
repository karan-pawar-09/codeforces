/*
author:Karan
created:24.08.2021 21:07:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
  
    ll k;
    ll ans=0;
    ll extrapower=0;
    vector<pair<ll,ll>> arr(n);

    for(ll i=0;i<n;i++) {
        cin>>k;
        ll temp=-1e18;
        ll a;
        vector<ll> ar(k);
        for(ll j=0;j<k;j++) {
            cin>>ar[j];
          
        }
        for(ll j=0;j<k;j++) {
            temp=max(temp,ar[j]-j+1);
        }
        arr[i].first=temp;
        arr[i].second=k;
    }
    sort(all(arr));
    for(ll i=0;i<n;i++) {
        if(ans+extrapower>=arr[i].first) {

        }
        else {
            ans=arr[i].first-extrapower;
        }
        extrapower+=arr[i].second;
    }
    cout<<ans<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}
