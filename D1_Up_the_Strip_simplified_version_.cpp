/*
author:Karan
created:25.08.2021 18:16:12
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll add(ll a,ll b,ll m) {
    return (a+b)%m;
}
ll subtract(ll a,ll b,ll m) {
    return (a-b+m)%m;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> dp(n+1),pref(n+1);
    dp[n]=1;
    pref[n]=1;
    for(ll i=n-1;i>0;i--) {
        dp[i]=pref[i+1];
        for(ll j=2;j*i<=n;j++) {
            dp[i]=add(dp[i],pref[i*j],m);
            if(((i+1)*j)<=n) {
                dp[i]=subtract(dp[i],pref[(i+1)*j],m);
            }
        }        
        pref[i]=add(dp[i],pref[i+1],m);
    }
    cout<<dp[1]<<endl;
}