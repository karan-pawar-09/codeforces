/*
    author:Karan
    created:23.03.2022 20:22:02
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
void solve() {
    ll n;
    cin >> n;
    ll k = 0;
    ll res = 0;
    while (power(2, k) <= n) {
        res++;
        k++;
    }
    cout << n - res << endl;
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
