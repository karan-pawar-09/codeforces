/*
    author:Karan
    created:07.07.2023 20:06:04
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
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0;i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        if (arr[i].first - arr[i].second > 0) {
            res++;
        }
    }
    cout << res << endl;
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