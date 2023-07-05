/*
    author:Karan
    created:29.06.2023 20:05:33
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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> dp(110, false);
    vector<int> arr;
    for (int i = 1; i <= k; i++) {
        if (i != x) {
            arr.push_back(i);
        }
    }
    dp[0] = true;
    vector<int> par(110, -1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (dp[i]) {
                if (i + arr[j] < 110) {
                    par[i + arr[j]] = i;
                    dp[i + arr[j]] = true;
                }
            }
        }
    }
    if (dp[n]) {
        cout << "YES" << endl;
        vector<int> res;
        for (int i = n; i != 0; i = par[i]) {
            res.push_back(i - par[i]);
        }
        cout << res.size() << endl;
        for (auto x : res) {
            cout << x << " ";
        }
        cout << endl;
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