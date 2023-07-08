/*
    author:Karan
    created:06.07.2023 12:53:41
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
    vector<ll> x(n);
    ll ct1 = 0;
    ll ct2 = 0;
    vector<ll> pref(m + 1, 0);
    vector<bool> isThere(m + 1, false);
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        cin >> x[i];
        if (x[i] == -1) {
            ct1++;
        }
        else if (x[i] == -2) {
            ct2++;
        }
        else {
            pref[x[i]] = 1;
            isThere[x[i]] = true;
        }
    }
    for (auto x : isThere) {
        if (x) total++;
    }
    for (ll i = 1; i <= m; i++) {
        pref[i] += pref[i - 1];
    }
    ll one = ct1 + total;
    ll two = ct2 + total;
    one = min(one, m);
    two = min(two, m);
    ll ans = max(one, two);
    for (ll i = 1; i <= m; i++) {
        if (isThere[i]) {
            ll back = i - 1;
            ll front = m - i;
            back = min(back, ct1 + pref[i - 1]);
            front = min(front, ct2 + total - pref[i]);
            ans = max(ans, back + front + 1);
        }
    }
    cout << ans << endl;
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