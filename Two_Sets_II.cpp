/*
author:Karan
created:27.06.2021 13:28:41
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod =(ll)1e9+7;

ll modExp(ll a, ll p) {
    a %= mod;
    ll res=1;
    while(p > 0) {
        if(p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
 }
 ll modInv(ll a) {
    return modExp(a,mod-2) % mod ;
 }
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum%2) {
        cout<<0<<endl;
    }
    else {
        ll m=sum/2;
        vector<ll> dp(m+1,0);
        dp[0]=1;
        for(ll i=1;i<=n;i++) {
            for(ll j=m;j>0;j--) {
                if(i<=j) {
                    dp[j]+=dp[j-i];
                    dp[j]%=mod;
                }
            }
        }
        cout<<(dp[m]*modInv(2))%mod<<endl;    
    }
}