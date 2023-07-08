/*
    author:Karan
    created:06.07.2023 20:06:40
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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<ll> res;
    ll total = 0;
    for (ll i = 1; i < n; i++) {
        total += abs(arr[i] - arr[i - 1]);
        res.push_back(abs(arr[i] - arr[i - 1]));
    }
    sort(all(res), greater<ll>());
    for (ll i = 0; i < (k - 1); i++) {
        total -= res[i];
    }
    cout << total << endl;
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