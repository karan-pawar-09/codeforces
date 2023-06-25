/*
    author:Karan
    created:24.06.2023 17:48:47
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
    string s;
    cin >> s;
    stack<ll> starts;
    vector<ll> dp(n+1, 0);
    for(ll i = 0; i < n; i++) {
        if(s[i] == '(') {
            starts.push(i);
        } else if(s[i] ==')') {
            if(starts.size()) {
                ll prev = starts.top();
                starts.pop();
                dp[prev]++;
                dp[i+1]--;
            }
        }
    }
    for(ll i = 1; i < n; i++) {
        dp[i] = dp[i] + dp[i-1];
    }
    for(ll i = 0; i < n; i++) {
        if(dp[i] == 0) cout<<s[i];
    }
    cout<<endl;
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