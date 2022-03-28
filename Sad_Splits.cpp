/*
    author:Karan
    created:19.03.2022 20:02:06
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
    int p = n % 10;
    bool first = false;
    bool second = false;
    string s = to_string(n);
    if (p % 2 == 0) {
        first = true;
        for (int i = 0;i < s.size() - 1;i++) {
            if ((s[i] - '0') % 2 == 0) {
                second = true;
            }
        }
    }
    else {
        first = true;
        for (int i = 0;i < s.size() - 1;i++) {
            if ((s[i] - '0') % 2) {
                second = true;
            }
        }
    }

    (first & second) ? cout << "YES" << endl : cout << "NO" << endl;
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