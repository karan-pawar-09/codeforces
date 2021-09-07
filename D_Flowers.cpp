/*
author:Karan
created:12.06.2021 15:31:48
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t,k;
    cin>>t>>k;

    ll mx=1e5+7;
    ll mod=1000000007;

    ll dp[mx];
    dp[0]=1;
    for(ll i=1;i<mx;i++) {
        if(i<k) {
            dp[i]=1;
        }
        else {
            dp[i]=(dp[i-1]%mod+dp[i-k]%mod)%mod;
        }
    }
    for(ll i=1;i<mx;i++) {
        dp[i]=(dp[i]%mod+dp[i-1]%mod)%mod;
    }
    cout<<endl;
    while(t--) {
        ll a,b;
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
    }
}