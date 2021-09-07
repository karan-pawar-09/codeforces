/*
author:Karan
created:21.06.2021 22:08:11
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
    vector<ll> dp(n+1,1e18+7);
    vector<ll> backtrack(n+1);
    dp[1]=0;
    for(ll i=2;i<=n;i++) {
        if((dp[i-1]+1)<dp[i]) {
            backtrack[i]=i-1;
            dp[i]=dp[i-1]+1;
        }
        if(i%2==0) {
            if(dp[i/2]+1<dp[i]) {
                backtrack[i]=i/2;
                dp[i]=dp[i/2]+1;
            }
        } 
        if(i%3==0) {
            if(dp[i/3]+1<dp[i]) {
                backtrack[i]=i/3;
                dp[i]=dp[i/3]+1;
            }
        }
    }
    vector<ll> ans;
    ll k=n;
    while(k!=1) {
        ans.push_back(k);
        k=backtrack[k];
    }
    ans.push_back(1);
    cout<<dp[n]<<endl;
    reverse(all(ans));
    for(ll i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}