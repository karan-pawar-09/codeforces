/*
    author:Karan
    created:23.03.2022 20:01:37
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0;
    int zero = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '0') zero++;
        else one++;
    }
    if (one == zero) {
        cout << min(one, zero) + min(one, zero) << endl;
    }
    else {
        cout << min(one, zero) + min(one, zero) + 1 << endl;
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