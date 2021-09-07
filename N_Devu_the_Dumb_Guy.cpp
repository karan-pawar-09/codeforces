#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans+=x*arr[i];
        if(x>1) {
            x--;
        }
    }
    cout<<ans<<endl;
}