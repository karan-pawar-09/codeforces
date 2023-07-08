/*
    author:Karan
    created:05.07.2023 15:05:18
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
    vector<ll> pos(n + 1);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i + 1;
    }
    ll ans = -1;
    vector<ll> dp(n+1, false);
    for(ll i = 1; i <= n; i++) {
        if(!dp[i]) {
            ll it = i;
            ll temp = -1;
            while(pos[it] != i && !dp[it]) {
                dp[it] = true;
                if(temp == -1) {
                    temp = abs(pos[it] - it);
                } else {
                    temp = __gcd(temp, abs(pos[it] - it));
                }
                it = pos[it];
            }
            if(temp == -1) {
                temp = abs(pos[it] - it);
            } else {
                temp = __gcd(temp, abs(pos[it] - it));
            }
            if(ans == -1) {
                ans = temp;
            } else {
                ans = __gcd(ans, temp);
            }
        }
    }
    cout << ans << endl;
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