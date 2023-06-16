/*
    author:Karan
    created:06.06.2023 20:16:13
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

ll dp[32];

ll rec(ll n, ll k) {
    if(n == 0) return 1;
    if(k == 0) return 1;
    ll p = 0;
    for(ll i=0;i < k && i< 32;i++) {
        if(n >= dp[i]) {
            p = dp[i];
        } else {
            break;
        }
    }
    return p + rec(n-p, k-1);
}
void solve() {
    ll n, k;
    cin >> n >> k;
    cout<<rec(n, k)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll res = 1;
    dp[0]= res;
    for(ll i=1;i<32;i++) {
        dp[i] = dp[i-1]*2;
    }
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}