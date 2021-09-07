/*
author:Karan
created:04.07.2021 17:35:31
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
    vector<ll> fact(15);
    fact[0]=1;
    fact[1]=1;
    for(ll i=2;i<15;i++) {
        fact[i]=fact[i-1]*i;
    }
    ll kk;
    cin>>kk;
    vector<ll> dp(kk+1,(ll)1e18+7);
    dp[0]=0;
    for(ll i=1;i<=kk;i++) {
        for(ll j=1;j<15;j++) {
            if(i>=fact[j]) {
                dp[i]=min(dp[i],dp[i-fact[j]]+1);
            }
        }
    }

    cout<<dp[kk]<<endl;
}