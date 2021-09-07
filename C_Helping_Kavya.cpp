#include<bits/stdc++.h>
using namespace std;
#define ll long long
int power (ll a,ll x) {
    int ans=0;
    while(a) {
        ans++;
        a/=x;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    int 
    cout<<ans<<endl;
}   