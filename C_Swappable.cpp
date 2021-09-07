/*
author:Karan
created:19.06.2021 17:39:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> freq(n,0);
    map<ll,ll> M;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(ll i=n-1;i>=0;i--) {
        if(M.find(arr[i])!=M.end()) {
            freq[i]=M[arr[i]];
        }
        M[arr[i]]++;
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans+=n-i-1-freq[i];
    }
    cout<<ans<<endl;
}