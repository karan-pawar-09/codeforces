

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll inf=1e18+10;

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll maxi=arr[0];
    ll index=0;
    for(ll i=0;i<n;i++) {
        if(arr[i]>maxi) {
            maxi=arr[i];
            index=i;
        }
    }
    arr[index]=-inf;
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans=max(ans,arr[i]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    ll t=1;
    while(t--) {
        solve();
    }
}