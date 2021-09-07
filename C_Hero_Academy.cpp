#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        ll avg=arr[n/2];
        ll ans=0;
        for(ll i=0;i<n;i++) {
            ans+=llabs(avg-arr[i]);
        }
        cout<<ans<<endl;
    }
}   