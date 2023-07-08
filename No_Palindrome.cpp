/*
    author:Karan
    created:05.07.2023 20:06:01
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
    ll n, k;
    cin >> n >> k;
    int len = k + (k - 1) / 2 + 2;
    int ans = (n / len) * 3;
    int rem = n % len;
    if (rem == 0) {

    }
    else {
        ans++;
        if (rem > (k + 1)) {
            ans += 2;
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