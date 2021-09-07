/*
author:Karan
created:04.07.2021 16:06:54
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
        if(n==1) {
            cout<<1<<endl;
        }
        else {
            vector<ll> prefix(n),suffix(n);
            prefix[0]=arr[0];
            suffix[n-1]=arr[n-1];
            for(ll i=1;i<n;i++) {
                prefix[i]=__gcd(arr[i],prefix[i-1]);
            }  
            for(ll i=n-2;i>=0;i--) {
                suffix[i]=__gcd(arr[i],suffix[i+1]);
            } 
            ll maxi=0;
            ll index=0;
            for(ll i=0;i<n;i++) {
                if(i==0) {
                    if(suffix[i+1]>=maxi) {
                        index=i;
                        maxi=suffix[i+1];
                    }
                }
                else if(i==n-1) {
                    if(prefix[i-1]>=maxi) {
                        index=i;
                        maxi=prefix[i-1];
                    }
                }
                else {
                    ll value=__gcd(prefix[i-1],suffix[i+1]);
                    if(value>=maxi) {
                        index=i;
                        maxi=value;
                    }
                }
            }
            arr[index]=maxi;
            ll ans=0;
            for(ll i=0;i<n;i++) {
                ans+=arr[i]/maxi;
            }
            cout<<ans<<endl;
        }
    }
}