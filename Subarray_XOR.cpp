/*
    author:Karan
    created:13.03.2022 11:18:40
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

const ll mod = (ll)998244353;

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll add(ll a, ll b) {
    return (a + b) % mod;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> arr(n, 0);
    for (ll i = 0;i < n; i++) {
        if (s[i] == '1') {
            arr[i] = (i + 1);
        } if (i > 0) {
            arr[i] += arr[i - 1];
        }
    }
    ll res = 0;
    for (ll i = 0;i < n;i++) {
        if (arr[n - 1 - i] % 2) res = add(res, power(2, i, mod));
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