/*
author:Karan
created:02.08.2021 23:48:37
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
        ll n,k,s;
        cin>>n>>k>>s;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            if(i>0) {
                arr[i]+=arr[i-1];
            }
        }
        vector<ll> p(n+1);
        p[n]=n;
        for(ll i=0;i<n;i++) {
            ll j;
            if(i>0)
                j=upper_bound(all(arr),arr[i-1]+s)-arr.begin();
            else 
                j=upper_bound(all(arr),s)-arr.begin();
            p[i]=j;
        }
        vector<ll> ans(n);
        for(ll i=0;i<n;i++) {
            ans[i]=i;
        }
        for(ll bit=0;bit<25;bit++) {
            if((k>>bit)&1) {
                for(ll i=0;i<n;i++) {
                    ans[i]=p[ans[i]];
                }
            }
            for(ll i=0;i<n;i++) {
                p[i]=p[p[i]];
            }
        }
        ll mx=0;

        for(ll i=0;i<n;i++) {
            mx=max(mx,ans[i]-i);
        }
        cout<<mx<<endl;
    }
}