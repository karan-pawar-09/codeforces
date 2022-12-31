/*
    author:Karan
    created:01.01.2023 01:29:41
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
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> dp(n * 2 + 10, 0);
    dp[0] = 1;
    ll xorr = 0;
    ll ans = 0;
    for (ll i = 0;i < n;i++) {
        xorr ^= arr[i];
        for (ll j = 0; j * j <= 2 * n; j++) {
            if (((j * j) ^ xorr) <= (2 * n)) {
                ans += dp[((j * j) ^ xorr)];
            }
        }
        dp[xorr]++;
    }
    cout<< ((n*(n+1))/2) - ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}