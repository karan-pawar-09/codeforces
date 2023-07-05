/*
    author:Karan
    created:01.07.2023 18:46:41
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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (ll i = 0; i < n;i++) {
        cin >> arr[i];
    }
    vector<pair<ll, ll>> ar(m);
    for (ll i = 0; i < m; i++) {
        cin >> ar[i].first;
    }
    for (ll i = 0; i < m;i++) {
        cin >> ar[i].second;
    }
    sort(all(arr));
    sort(all(ar));
    ll ind = 0;
    multiset<ll, greater<ll>> ms;
    ll discount = 0;
    for (ll i = 0; i < n; i++) {
        while (ind < m && ar[ind].first <= arr[i]) {
            ms.insert(ar[ind].second);
            ind++;
        }
        if(ms.size()) {
            discount += *ms.begin();
            ms.erase(ms.begin());
        }
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        res += arr[i];
    }
    cout << res - discount << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;

    while (t--) {
        solve();
    }
}
