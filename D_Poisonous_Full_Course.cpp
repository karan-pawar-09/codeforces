/*
    author:Karan
    created:17.06.2023 17:51:39
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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> dp(n+1, {0, 0});
    for(ll i = 1; i <= n; i++) {
        ll a, b;
        cin >> a >> b;
        if(a == 0) {
            {
                dp[i].first = max(dp[i].first, max(dp[i-1].first, dp[i-1].second) + b);
            } 
            {
                dp[i].first = max(dp[i].first, dp[i-1].first);
                dp[i].second = max(dp[i].second, dp[i-1].second);
            }
        } else {
            {
                dp[i].second = max(dp[i].second, dp[i-1].first + b);
            }
            {
                dp[i].first = max(dp[i].first, dp[i-1].first);
                dp[i].second = max(dp[i].second, max(dp[i-1].first, dp[i-1].second));
            }
        }
    }
    // for(ll i = 0; i <= n; i++) {
    //     cout<<dp[i].first<<" "<<dp[i].second<<endl;
    // }
    cout<<max(dp[n].first, dp[n].second)<<endl;
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