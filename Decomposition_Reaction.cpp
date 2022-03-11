/*
    author:Karan
    created:09.03.2022 21:29:34
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

ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll mul(ll a, ll b) {
    return (a * b) % mod;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n + 1, 0);
    for (ll i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    while (m--) {
        ll p, x;
        cin >> p >> x;
        ll w, c;
        for (ll i = 0;i < x;i++) {
            cin >> w >> c;
            arr[c] = add(arr[c], mul(arr[p], w));
        }
        arr[p] = 0;
    }
    for (ll i = 1;i <= n;i++) {
        cout << arr[i] << endl;
    }
    
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

dsu