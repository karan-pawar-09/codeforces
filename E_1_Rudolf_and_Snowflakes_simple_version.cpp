/*
    author:Karan
    created:07.07.2023 20:59:15
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

ll power(long long x, unsigned ll y) {
    ll res = 1;
    x = x;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

ll sumpower(ll k, ll n) {
    return (power(k, n) - 1) / (k - 1);
}

ll binary_search(ll k, ll n) {
    ll l = 3;
    ll r = 64;
    ll start = -1;
    for (ll i = l; i <= r; i++) {
        ll xx = sumpower(k, i);
        if (sumpower(k, i) <= n) {
            start = i;
        }
        else {
            break;
        }
    }
    if (start == -1) {
        return -1;
    }
    else {
        return sumpower(k, start);
    }
}

void solve() {
    ll n;
    cin >> n;
    ll l = 2;
    for (ll i = l; i <= sqrt(n); i++) {
        ll count = binary_search(i, n);
        if (count == n) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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