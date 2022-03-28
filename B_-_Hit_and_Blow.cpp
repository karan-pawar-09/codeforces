/*
    author:Karan
    created:14.03.2022 22:22:22
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
    vector<ll> a(n), b(n);
    for (ll i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (ll i = 0;i < n;i++) {
        cin >> b[i];
    }
    ll res = 0;
    ll res1 = 0;
    for (ll i = 0;i < n;i++) {
        if (a[i] == b[i]) {
            res++;
        }
    }
    for (ll i = 0;i < n;i++) {
        for (ll j = 0;j < n;j++) {
            if (i != j and a[i] == b[j]) {
                res1++;
            }
        }
    }
    cout << res << endl;
    cout << res1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}