/*
    author:Karan
    created:27.01.2023 20:39:46
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
    cin>>n;
    vector<ll> dp(n+1);
    ll a;
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n-1;j++) {
            cin>>a;
            dp[a] += j;
        }
    }
    vector<ll> arr(n);
    iota(all(arr), 1);
    sort(all(arr), [&](ll p, ll q) {
        return dp[p] < dp[q];
    });
    for(auto x: arr) {
        cout<<x<<" ";
    }
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