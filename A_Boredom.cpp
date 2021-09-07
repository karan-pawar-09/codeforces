/*
author:Karan
created:25.06.2021 13:03:31
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
    ll n;
    cin>>n;
    ll N=(ll)1e6+7;
    vector<ll> arr(n);
    vector<ll> count(N,0);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        count[arr[i]]++;
    }
    vector<ll> dp(N,0);
    dp[1]=count[1];
    for(ll i=2;i<N;i++) {
        dp[i]=max(dp[i-1],dp[i-2]+count[i]*i);
    }
    cout<<dp[N-1]<<endl;
}