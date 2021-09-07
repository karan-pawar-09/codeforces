#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll ans=0;
    for(ll i=1;i<n;i++) {
        if(arr[i]<arr[i-1]) {
            ans+=(arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
    cout<<ans<<endl;
}