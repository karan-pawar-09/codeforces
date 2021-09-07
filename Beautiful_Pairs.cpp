/*
author:Karan
created:31.07.2021 19:02:56
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> arr(n);
        ll ans=0;
        map<ll,ll> M;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        M[arr[n-1]]++;
        for(ll i=n-2;i>=0;i--) {
            if(M.find(arr[i])!=M.end()) {
                ans+=n-i-1-M[arr[i]];
            }
            else {
                ans+=n-i-1;
            }
            M[arr[i]]++;
        }
        cout<<2*ans<<endl;
    }
}