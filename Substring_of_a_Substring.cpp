/*
    author:Karan
    created:13.03.2022 11:07:59
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
    int len = 0;
    int res = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[0] and s[i] != s[s.size() - 1]) {
            res++;
        }
        else {
            res = 0;
        }
        len = max(len, res);
    }
    len ? cout << len << endl : cout << "-1" << endl;
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