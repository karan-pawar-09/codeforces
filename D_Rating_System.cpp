/*
    author:Karan
    created:01.07.2023 12:31:05
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
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (ll i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }
    ll maxtill = 0;
    ll ans = 0;
    ll ansmax = 0;
    for (ll i = 0; i < n; i++) {
        if (maxtill - arr[i] > ans) {
            ans = maxtill - arr[i];
            ansmax = max(ansmax, maxtill);
        }
        maxtill = max(maxtill, arr[i]);
    }
    cout << ansmax << endl;
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