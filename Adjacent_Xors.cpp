/*
    author:Karan
    created:10.08.2022 21:18:59
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

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<ll>> dp(n, vector<ll> (2,0));
    for(ll i=1;i<n;i++) {
        dp[i][0] = max(((arr[i]+x)^(arr[i-1]+x))+dp[i-1][0], ((arr[i]+x)^arr[i-1]) + dp[i-1][1] );
        dp[i][1] = max(((arr[i])^(arr[i-1]+x))+dp[i-1][0], ((arr[i])^arr[i-1]) + dp[i-1][1] );
    }
    cout<<max(dp[n-1][0], dp[n-1][1])<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}