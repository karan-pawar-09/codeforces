/*
    author:Karan
    created:07.07.2023 20:12:54
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

bool check(vector<string>& arr, char c) {
    ll n = 3;
    for (ll i = 0; i < n; i++) {
        ll cnt = 0;
        for (ll j = 0; j < n; j++) {
            if (arr[i][j] == c) cnt++;
        }
        if (cnt == n) return true;
    }
    for (ll j = 0; j < n;j++) {
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            if (arr[i][j] == c) cnt++;
        }
        if (cnt == n) return true;
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (arr[i][i] == c) cnt++;
    }
    if (cnt == n) return true;
    cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (arr[i][2 - i] == c) cnt++;
    }
    if (cnt == n) return true;
    return false;
}
void solve() {
    ll n = 3;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (check(arr, '+')) {
        cout << "+" << endl;
    }
    else if (check(arr, 'X')) {
        cout << "X" << endl;
    }
    else if (check(arr, 'O')) {
        cout << "O" << endl;
    }
    else {
        cout << "DRAW" << endl;
    }
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