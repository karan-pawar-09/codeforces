/*
author:Karan
created:28.08.2021 20:14:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll  mod=1e9+7;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n-1;i++) {
        cin>>a[i];
    }   
    vector<ll> val(n);
    for(ll i=0;i<n;i++) {
        cin>>val[i];
    }
    sort(all(val));
    vector<ll> dp(n),sum(n);
    dp[0]=0;
    sum[0]=0;
    for(ll i=1;i<n;i++) {
        if(val[i]>val[i-1]) {
            dp[i]=sum[i-1]+i;
        }
        else {
            dp[i]=dp[i-1];
        }
        sum[i]=sum[i-1]+dp[i];
        dp[i]=dp[i]%mod;
        sum[i]=sum[i]%mod;
    }
    for(int i=0;i<n;i++) {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    cout<<dp[n-1]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}