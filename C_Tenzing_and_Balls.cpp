/*
    author:Karan
    created:24.06.2023 19:58:34
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
    vector<ll> next(n, -1);
    map<ll, ll> M;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(ll i = n -1; i >= 0; i--) {
        if(M.find(arr[i]) != M.end()) {
            next[i] = M[arr[i]];
        }
        M[arr[i]] = i;
    }
    vector<ll> dp(n, 0);
    for(ll i = 0; i < n; i++) {
        ll prev = 0;
        if(i > 0) {
            prev = dp[i-1];
        }
        if(next[i] != -1) {
            dp[next[i]] = max({dp[next[i]], prev + (next[i] - i + 1), dp[i] + next[i] - i});
        }
        dp[i] = max(dp[i], prev);
    }
    cout<<dp[n-1]<<endl;
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