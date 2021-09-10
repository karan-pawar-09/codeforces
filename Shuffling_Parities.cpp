/*
    author:Karan
    created:10.09.2021 16:43:55
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> odd,even;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]%2) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    }    
    ll od=n/2;
    ll ev=n/2;
    if(n%2) ev++;
    ll ans=0;
    ans+=min(od,(ll)odd.size());
    ans+=min(ev,(ll)even.size());
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