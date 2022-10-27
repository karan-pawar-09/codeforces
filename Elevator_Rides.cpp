/*
    author:Karan
    created:14.10.2022 14:57:37
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
 
const ll mx = 21;
ll arr[mx];
ll dp[1<<mx];

ll rec(ll bit, ll count, ll wt, int rem, int n, int x) {
    if(rem == 0) {
        return count;
    }
    if(dp[bit] != -1) {
        return dp[bit];
    }
    ll mini = 50;
    for(ll i=0;i<n;i++) {
        if((1<<i)&bit) {
            bit ^= (1<<i);
            wt -= arr[i];
            if(wt < 0) {
                mini = min(mini, rec(bit, count+1, x-arr[i], rem-1, n, x));
            } else {
                mini = min(mini, rec(bit, count, wt, rem-1, n, x));
            }
            wt += arr[i];
            bit ^= (1<<i);
        }
    }
    dp[((1<<n)-1) ^ bit] = mini;
    return mini;
 
}
void solve() {
    ll n, x;
    cin>>n>>x;
    for(ll i=0;i<(1<<mx);i++) {
        dp[i] = -1;
    }
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<rec((1<<n)-1, 1, x, n, n ,x)<<endl;
    // for(int i=1;i<=((1<<n)-1);i++) {
    //     cout<<dp[i]<<endl;
    // }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}