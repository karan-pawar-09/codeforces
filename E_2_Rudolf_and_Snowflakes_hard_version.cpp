/*
    author:Karan
    created:07.07.2023 21:29:54
*/

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))



ll isGood(ll &k, ll &pr, ll &n) {
    ll sum = 0;
    ll pwr = 1;
    for (ll i = 0; i < pr; i++) {
        sum += pwr;
        if(sum > n) return 2e18;
        if((2e18)/k < pwr) {
            pwr = 2e18;
        } else {
            pwr *= k;
        }
    }
    return sum;
}

bool binary_search(ll &pr, ll &n) {
    ll l = 2;
    ll r = 1e18 + 1;
    while (l + 1 < r) {
        ll m = (l + r) >> 1;
        ll res = isGood(m, pr, n);
        if (res <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }
    if(isGood(l, pr, n) == n) return true;
    else return false;
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = 3; i < 61; i++) {
        if (binary_search(i, n)) {
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