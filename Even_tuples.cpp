/*
author:Karan
created:24.07.2021 15:22:52
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
        ll n,q;
        cin>>n>>q;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> odd(n+1,0);
        vector<ll> even(n+1,0);
        if(arr[0]%2==0) {
            even[1]=1;
        }
        else{
            odd[1]=1;
        }
        for(ll i=2;i<=n;i++) {
            if(arr[i-1]%2) {
                odd[i]=odd[i-1]+1;
                even[i]=even[i-1];
            }
            else {
                odd[i]=odd[i-1];
                even[i]=even[i-1]+1;
            }
        }
        while(q--) {
            ll l,r;
            cin>>l>>r;
            ll odds=odd[r]-odd[l-1];
            ll evens=even[r]-even[l-1];
            // cout<<odds<<" "<<evens<<endl;
            ll ans=max((odds*(odds-1))/2*evens,0LL)+max((evens*(evens-1)*(evens-2)/6),0LL);
            cout<<ans<<endl;
        }
    }
}