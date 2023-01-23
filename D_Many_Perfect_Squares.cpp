/*
    author:Karan
    created:23.01.2023 09:25:56
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

/*

a+x = k^2
b+x = r^2

(a-b) = (k-r) * (k+r)

k+r = q
k-r = p
k = (p+q)/2;
*/

bool isSquare(ll a) {
    ll p = floorl(sqrtl(a));
    return (p * p == a);
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    ll ans = 1;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll diff = arr[j] - arr[i];
            for (ll k = 1; k * k <= diff; k++) {
                if (diff % k == 0) {
                    ll p = min(k, diff / k);
                    ll q = max(k, diff / k);
                    if ((p + q) % 2 == 0) {
                        ll kx = (p + q) / 2;
                        ll x = (kx * kx) - arr[j];
                        if (x >= 0) {
                            ll temp = 0;
                            for (auto it : arr) {
                                if (isSquare(it + x)) {
                                    temp++;
                                }
                            }
                            ans = max(ans, temp);
                        }
                    }
                }
            }
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