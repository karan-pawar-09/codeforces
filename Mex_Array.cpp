/*
    author:Karan
    created:28.06.2023 20:19:52
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
    vector<ll> dp(n+1, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        dp[arr[i]]++;
    }
    vector<ll> ans;
    ll cur = 0;
    while(dp[0] != 0) {
        ll count = 0;
        for(ll i = 0; i <= n; i++) {
            if(dp[i]) {
                dp[i]--;
                count++;
            } else {
                break;
            }
        }
        cur += count;
        ans.push_back(count);
    }
    for(ll i = 0; i < (n - cur); i++) {
        ans.push_back(0);
    }
    cout<<ans.size()<<endl;
    for(auto x: ans) cout << x << " ";
    cout<<endl;
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