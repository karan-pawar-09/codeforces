/*
    author:Karan
    created:03.06.2023 20:06:49
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

ll ceil(ll a, ll b) {
    return (a+b-1)/b;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n+1), dp1(n+1);
    ll req = 0;
    for(ll i=1;i<=n;i++) {
        if(req >= ceil(i, k)) {
            dp[i] = 0;
        } else {
            req++;
            dp[i] = 1;
        }
    }
    req = 0;

    for(ll i=n;i>=1;i--) {
        if(req >= ceil(n-i+1, k)) {
            dp1[i] = 0;
        } else {
            req++;
            dp1[i] = 1;
        }
    }
    ll count = 0;
    for(ll i=1;i<=n;i++) {
        count += (dp[i] | dp1[i]);
    }
    // for(ll i=1;i<=n;i++) {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    // for(ll i=1;i<=n;i++) {
    //     cout<<dp1[i]<<" ";
    // }
    //cout<<endl;
    req = 0;
    ll temp = 0;
    for(ll i=1;i<=n;i++) {
        if(dp[i] ^ dp1[i]) {
            if(dp[i]) { 
                if(temp > 0) {
                    temp--;
                } else {
                    req++;
                }
            } else {
                req++;
                temp++;
            }
        } else {
            if(dp[i]) {
                req++;
            }
        }
    }
    
    cout<<req<<endl;
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