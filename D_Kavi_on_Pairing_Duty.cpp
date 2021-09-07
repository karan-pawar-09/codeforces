/*
author:Karan
created:25.05.2021 11:01:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    ll mod=998244353;
    vector<ll> dp(n+1);
    for(int i=1;i<=n;i++) {
        for(int j=i+i;j<=n;j+=i) {
            dp[j]++;
        }
    }
    dp[0]=1;
    ll S=1;
    for(int i=1;i<=n;i++) {
        dp[i]=(S%mod+dp[i]%mod)%mod;
        S=(dp[i]%mod+S%mod)%mod;
    }
    cout<<dp[n]<<endl;
}