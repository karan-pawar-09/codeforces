

/*
4 2
3 2
2 2
2 1
2 0
*/

/*
    author:Karan
    created:29.01.2023 20:55:21
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

ll binarysearch1(ll n, ll k) {
    ll a = min(k, n);
    ll b = n-k;
    b= max(0LL, b);
    a++;
    ll l = b;
    ll r = a;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(((m-k) * (n-m-k)) >= 0 ) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
ll binarysearch(ll n, ll k) {
    ll a = k;
    ll b = n-k;
    if(a>b) {
       return binarysearch1(n, k);
    }
    a = min(n, k);
    b = max(0LL, n-k);
    a--;
    ll l = a;
    ll r = b;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(((m-k) * (n-m-k)) >= 0) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}
ll calc(vector<ll> temp, vector<ll> temp1, vector<ll> arr) {
    ll n = temp.size();
    ll ans = 0;
    for(ll i=1;i<n-2;i++) {
        ans += temp1[i]*temp[i+1];
    }
    ans += temp[1]*arr[0];
    ans += arr[n-1] * temp1[n-2];
    return ans;
}
void solve() {
    ll n, s;
    cin>>n>>s;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> temp(n);
    vector<ll> temp1(n);
    for(ll i=1;i<n-1;i++) {
        temp[i] = binarysearch(arr[i], s);
        temp1[i] = arr[i]-temp[i];
    }
    vector<pair<ll, ll>> dp(n, {0, 0});
    dp[1].first = temp[1] * arr[0];
    dp[1].second = temp1[1] * arr[0];
    for(ll i=2;i<n-1;i++) {
        ll a = min(dp[i-1].second + temp[i] *temp[i-1], dp[i-1].first + temp1[i-1] * temp[i]);
        ll b = min(dp[i-1].first+ temp1[i-1]*temp1[i], dp[i-1].second+temp[i-1]*temp1[i]);
        dp[i].first = a;
        dp[i].second = b;
    }
    dp[n-1].first = dp[n-2].second + temp[n-2] * arr[n-1];
    dp[n-1].second = dp[n-2].first + temp1[n-2] * arr[n-1];
    
    cout<<min(dp[n-1].first, dp[n-1].second)<<endl;
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