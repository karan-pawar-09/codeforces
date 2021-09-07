/*
author:Karan
created:22.08.2021 23:31:47
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
        ll n,k,x;
        cin>>n>>k>>x; 
        vector<ll> ar(n); 
        ll sum=0;
        for(ll i=0;i<n;i++) {
            cin>>ar[i];
            sum+=ar[i];
        }
        sort(all(ar));
        int p=n-1;
        while(k--){
            if(ar[p]+ar[p-1]>x)sum-=(ar[p]+ar[p-1]-x);
            p-=2;
        }
        cout<<sum<<endl;
    }
}