/*
author:Karan
created:04.07.2021 11:30:21
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
        vector<ll> arr(2*n);
        for(ll i=0;i<2*n;i++) cin>>arr[i];
        ll odd=0;
        for(ll i=0;i<2*n;i++) {
            if(arr[i]%2) odd++;
        }
        odd==n?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
}