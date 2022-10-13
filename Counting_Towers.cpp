/*
    author:Karan
    created:13.10.2022 15:48:47
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif
 
const ll mod = 1e9+7;
const ll mx = 1e6+10;
 
ll mul(ll a, ll b) {
    return (a*b)%mod;
}
ll add(ll a, ll b) {
    return (a+b)%mod;
}
 
ll dp[mx][2];

void solve() {
    ll n;
    cin>>n;
    cout<<add(dp[n-1][0], dp[n-1][1])<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    dp[0][0]=1;
    dp[0][1]=1;
    for(ll i=1;i<mx;i++) {
        dp[i][0] = mul(2, add(dp[i-1][0], dp[i][0]));
        dp[i][0] = add(dp[i-1][1], dp[i][0]);
        dp[i][1] = mul(4, add(dp[i-1][1], dp[i][1]));
        dp[i][1] = add(dp[i-1][0], dp[i][1]);
    }
    while(t--) {
        solve();
    }
}
 
 
 
/*
 
|_| |_| 
| | | |
 
|     |
|     |
 
|_  _ |
|     |
 
 
*/