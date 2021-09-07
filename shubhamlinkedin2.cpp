
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll dp[21][(1<<21)];

ll solve(ll i,ll bit,ll &n) {
    if(i>=n+1) {
        return 1;
    }
    ll ans=0;
    if(dp[i][bit]!=-1) {
        return dp[i][bit];
    }
    for(ll j=1;j<=n;j++) {
        if(bit&(1<<j) and ((i%j==0 || j%i==0))) {            
            ans+=solve(i+1,bit^(1<<j),n);            
        }
    }
    return dp[i][bit]=ans;
}
ll arrangements(ll n) {
    memset(dp,-1,sizeof(dp));   
    return solve(1,(1<<(n+1))-1,n);
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    cout<<arrangements(n)<<endl;
}