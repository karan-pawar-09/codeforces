/*
author:Karan
created:29.08.2021 16:04:27
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
        ll sum1=0;
        ll sum2=0;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
            sum1+=arr[i];
        }
        vector<ll> ar(n-1);
        for(ll i=0;i<n-1;i++) {
            cin>>ar[i];
            sum2+=ar[i];
        }
        sort(all(arr));
        sort(all(ar));
        set<ll> index;
        for(ll i=0;i<n;i++) {
            if(((sum2-sum1+arr[i])%(n-1)==0) and ((sum2-sum1+arr[i])>0) ) {
                index.insert(i);
            }
        }
        if(index.size()!=0) {
            ll ans=1e18;
            if(index.find(0)!=index.end()) {
                ans=min(ans,ar[0]-arr[1]);
            }
            ans=min(ans,ar[0]-arr[0]);
            cout<<ans<<endl;
        }
        else {
            cout<<ar[1]-arr[1]<<endl;
        }
    }
}