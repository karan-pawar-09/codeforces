/*
    author:Karan
    created:22.11.2022 18:21:20
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

const ll inf = 1e18+10;

bool isGood(ll m, ll n, ll k, vector<ll> &arr) {
    vector<pair<ll, ll>> dp(n, {0, 0});
    vector<pair<ll, ll>> prev(n, {-inf, -inf});
    dp[0].first = 1;
    prev[0].first = arr[0];
    for(ll i=1;i<n;i++) { 
        if(arr[i]-prev[i-1].first >= m) {
            dp[i].first = max(dp[i-1].first, dp[i-1].second)+1;
            prev[i].first = arr[i];
        } else if(arr[i]-prev[i-1].first < m && arr[i]-prev[i-1].second >= m){
            dp[i].first = dp[i-1].second + 1;
            prev[i].first = arr[i];
        } else  {
            dp[i].first = 0;
            prev[i].first = inf;
        } 
    
        if(dp[i-1].first > dp[i-1].second) {
            dp[i].second = dp[i-1].first;
            prev[i].second = prev[i-1].first;
        } else {
            dp[i].second = dp[i-1].second;
            prev[i].second = prev[i-1].second;
        } 
    }
    return max(dp[n-1].first, dp[n-1].second) >= k;
}

ll binarysearch(ll n, ll k, vector<ll> &arr) {
    ll l = 0;
    ll r = 1e12+10;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(isGood(m, n, k, arr)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<binarysearch(n, k, arr)<<endl;
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