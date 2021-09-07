/*
author:Karan
created:30.06.2021 12:45:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mod=(int)1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,k,d;
    cin>>n>>k>>d;
    vector<ll> dp(n+1,0),dk(n+1,0);
    dp[0]=1;
    for(ll i=1;i<=n;i++) {
        for(ll j=max(i-k,0LL);j<i;j++) {
            dp[i]=(dp[i]+dp[j])%mod;
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=max(i-k,0LL);j<=i-d;j++) {
            dk[i]=(dk[i]+dp[j])%mod;
        }
        for(ll j=max(i-d+1,0LL);j<i;j++) {
            dk[i]=(dk[i]+dk[j])%mod;
        }
    }
    cout<<dk[n]<<endl;
}