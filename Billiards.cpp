#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+9;
    ll t;
    cin>>t;
    ll x;
    x=(ll)1e6;
    vector<ll> dp(x+1,0);
    if(x>=2) {
        dp[2]=1;
        if(x>=3) {
            dp[3]=1;
        }
    }        
    for(ll i=4;i<=x;i++) { 
        if(i==4) {
            dp[i]=1;
        }        
        else{
            dp[i]=(dp[i-2]%mod+dp[i-3]%mod)%mod;
        }               
    }
    while(t--) {
        int k;
        cin>>k;
        cout<<dp[k]%mod<<endl;
    }
}