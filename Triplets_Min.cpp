/*
    author:Karan
    created:05.07.2023 20:19:31
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

ll binary_search(ll n, vector<ll>& arr) {
    ll l = -1;
    ll r = arr.size() - 1;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (arr[m] >= n) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}


ll nc3(ll n) {
    return (n * ( n - 1) * (n - 2))/ 6;
}
ll nc2(ll n) {
    return (n * (n - 1))/ 2;
}
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(all(arr));

    vector<ll> dp(n - 2);

    for (ll i = 0; i < n - 2; i++) {
        dp[i] = nc2(n - 1 - i);
    }
    for (ll i = 1; i < n - 2; i++) {
        dp[i] += dp[i - 1];
    }

    assert(dp.back() == nc3(n));

    while (q--) {
        ll a;
        cin >> a;

        cout << arr[binary_search(a, dp)] << endl;
    }
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