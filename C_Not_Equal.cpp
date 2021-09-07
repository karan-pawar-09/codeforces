/*
author:Karan
created:10.07.2021 17:37:53
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    ll ans=1;
    ll k=0;
    for(ll i=0;i<n;i++) {
        ans=((ans)%mod*(arr[i]-k+mod)%mod)%mod;     
        k++;
    }
    cout<<ans<<endl;
}