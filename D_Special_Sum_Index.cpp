
//FUCKKKKKKK
//should've used ll

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n+1,0);
    for(ll i=1;i<=n;i++) {
        cin>>arr[i];
    }
    for(ll i=1;i<=n;i++) {
        arr[i]+=arr[i-1];
    }
    ll max=-(ll)1e9+7;
    ll ans=1;
    for(ll i=n;i>=1;i--) {
        ll s=(sqrt(1+(8*(n+1-i)))-1)/2;
        ll end=(s*(s+1))/2;
        ll temp=arr[i+end-1]-arr[i-1];
        if(temp>=max) {
            max=temp;
            ans=i;
        }
    }
    cout<<ans<<endl;
}
