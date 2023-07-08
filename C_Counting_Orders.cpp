/*
    author:Karan
    created:05.07.2023 15:54:34
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

const ll mod = 1e9 + 7;

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll binary_search(ll no, vector<ll>& a) {
    ll l = -1;
    ll r = a.size() - 1;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (a[m] > no) {
            r = m;
        }
        else {
            l = m;
        }
    }
    if (a[r] > no) return r;
    else return -1;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(all(a));
    vector<ll> pref(n, 0);
    for (ll i = 0; i < n; i++) {
        ll index = binary_search(b[i], a);
        if (index != -1) {
            pref[index]++;
        }
    }
    for (ll i = 1; i < n; i++) {
        pref[i] += pref[i - 1];
    }
    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        ll options = pref[i] - i;
        ans = mul(ans, options);
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