/*
author:Karan
created:04.07.2021 15:49:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n,k;
    cin>>n>>k;
    vector<ll> ones(33,0LL);
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        for(ll j=0;j<32;j++) {
            if(arr[i]&(1<<j)) {
                ones[j]++;
            }
        }
    }
    ll ans=0;
    for(ll i=0;i<33;i++) {
        ans+=(ones[i]+k-1)/k;
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