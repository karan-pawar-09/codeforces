/*
    author:Karan
    created:06.06.2023 21:35:28
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
ll dp[(ll)2e5+10];

ll sumfrom(ll i, ll j) {
    ll ans = dp[j];
    if(i > 0) {
        ans -= dp[i];
    }
    return ans;
}

ll binarysearch(vector<ll> &arr, ll start, ll n) {
    ll l = start+1;
    ll r = n-1;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(arr[m] - arr[start+1] <=  arr[n-1] - arr[m+1]) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    if(n <= 3) {
        cout<<0<<endl;
        return;
    }
    dp[0] = arr[0];
    for(ll i=1;i<n;i++) {
        dp[i] = dp[i-1] + arr[i];
    }
    ll ans = 1e18+10;
    for(ll i=0;i<n-2;i++) {
        ll sum1 = arr[i] - arr[0];
        ll index = binarysearch(arr, i, n);
        // ll sum2 = sumfrom(i+1, index);
        ll sum2 = arr[index] - arr[i+1];
        // ll sum3 = sumfrom(index+1, n-1);
        ll sum3 = arr[n-1] - arr[index+1];
        ll maxi = max({sum1, sum2, sum3});
        if(index < n-2) {
            index++;
            sum1 = arr[i] - arr[0];
            sum2 = arr[index] - arr[i+1];
            sum3 = arr[n-1] - arr[index+1];
            maxi = min(maxi, max({sum1, sum2, sum3}));
        }
        //cout<<maxi<<" ";
        ans = min(ans, ceil(maxi, 2));
    }
    //cout<<endl;
    cout<<ans<<endl;

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