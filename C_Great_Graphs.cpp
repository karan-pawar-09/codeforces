/*
author:Karan
created:25.06.2021 22:33:13
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
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        sort(all(arr));
        ll ans=0;
        ll res=0;
        ll k=1;
        for(ll i=0;i<n;i++) {
            if(arr[i]<0||i==0) {
                ans+=arr[i];
            }
            else {
                ans+=arr[i]-arr[i-1];
                res+=k*(arr[i]-arr[i-1]);
                k++;
                ans-=res;
            }
        }
        cout<<ans<<endl;
    }
}