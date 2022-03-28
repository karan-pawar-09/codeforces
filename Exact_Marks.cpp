/*
    author:Karan
    created:13.03.2022 10:59:07
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

int ceil(int a, int b) {
    return (a + b - 1) / b;
}
void solve() {
    int n, x;
    cin >> n >> x;
    int p = ceil(x, 3);
    int rem = n - p;
    int res = 3 * p - x;
    if (res <= rem) {
        cout << "YES" << endl;
        cout << p << " " << res << " " << n - (p + res) << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}