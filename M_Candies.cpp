/*
author:Karan
created:27.06.2021 18:17:31
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
    ll n,k;
    cin>>n>>k;
    vector<ll> arr(n);
    vector<ll> dp(k+1,0);
    for(ll i=0;i<n;i++) cin>>arr[i];
    dp[0]=1;
    for(ll i=0;i<n;i++) {
        vector<ll> prefix(k+1);
        prefix[0]=dp[0];
        for(ll j=1;j<=k;j++) {
            prefix[j]=(prefix[j-1]+dp[j])%mod;
        }
        for(ll j=k;j>=0;j--) {
            ll tmp=dp[j];
            ll l= j-arr[i]-1;
            ll r=j;
            if(r>=l) {
                if(l>=0)
                    dp[j]=(prefix[r]-prefix[l]+mod)%mod;
                else 
                    dp[j]=prefix[r];
            }
                
        }
    }
    cout<<dp[k]<<endl;
}