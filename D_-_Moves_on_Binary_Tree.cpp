/*
    author:Karan
    created:15.03.2022 14:34:44
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
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    int u = 0;
    int used = 0;
    for (int i = n - 1;i >= 0;i--) {
        if (s[i] == 'U') {
            u++;
        }
        else {
            if (u > 0) {
                u--;
                s[i] = 'X';
                used++;
            }
        }
    }
    for (int i = n - 1;i >= 0;i--) {
        if (s[i] == 'U') {
            if (used > 0) {
                used--;
                s[i] = 'X';
            }
            else {
                break;
            }
        }
    }
    for (ll i = 0;i < n;i++) {
        if (s[i] == 'U') {
            x = x / 2;
        }
        else if (s[i] == 'L') {
            x *= 2;
        }
        else if (s[i] == 'R') {
            x = (x * 2) + 1;
        }
    }
    cout << x << endl;
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