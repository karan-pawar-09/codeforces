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
const pair<ll, ll> invalid = {50, 1e9+10};
ll arr[mx];
pair<ll, ll> dp[1<<mx];
ll n, x;


void solve() {
    cin>>n>>x;
    for(ll i=0;i<(1<<n);i++) {
        dp[i] = invalid;
    }
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    dp[0].first = 0;
    dp[0].second = 1e9+10;
    for(ll i=1;i<(1<<n);i++) {
        for(ll j=0;j<n;j++) {
            if(i&(1<<j)) {
                ll prev = dp[i^(1<<j)].second;
                ll count = dp[i^(1<<j)].first;
                if(arr[j]+prev <= x) {
                    prev += arr[j];
                    dp[i] = min(dp[i], {count, prev});
                } else {
                    prev = min(prev, arr[j]);
                    count++;
                    dp[i] = min(dp[i], {count, prev});
                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
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