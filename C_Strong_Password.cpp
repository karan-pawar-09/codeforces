/*
    author:Karan
    created:29.06.2023 21:06:08
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
    string s;
    cin >> s;
    ll n = s.size();
    ll m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    ll used = 0;
    ll index = 0;
    ll can = 0;
    for (ll i = 0; i < m; i++) {
        can = 0;
        for (char c = l[i]; c <= r[i]; c++) {
            can |= (1 << (c - '0'));
        }
        while ((index < n)) {
            if ((can & (1 << (s[index] - '0')))) {
                can ^= (1 << (s[index] - '0'));
                index++;
            }
            else {
                index++;
            }
            if (can == 0) {
                break;
            }
        }
        if (i != m - 1) {
            if (index == n) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
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