/*
    author:Karan
    created:09.03.2022 20:24:10
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
    int res = 0;
    for (int i = 0;i < n;i++) {
        if (i + 1 < n and s[i] == s[i + 1]) {
            i++;
            res++;
        }
        else {
            res++;
        }
    }
    cout << res << endl;
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