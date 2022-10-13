/*
    author:Karan
    created:04.08.2022 11:55:32
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

int findEarliestMonth(vector<int> ar) {
    vector<ll> arr;
    for (auto x : ar) {
        arr.push_back(x);
    }
    int n = arr.size();
    ll sum = 0;
    for (int i = 0;i < n;i++) {
        sum += arr[i];
    }
    vector<ll> pre(n);
    pre[0] = arr[0];
    for (int i = 1;i < n;i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    ll ans = 1e18 + 10;
    int res = 0;
    for (int i = 0;i < n - 1;i++) {
        ll avg1 = pre[i] / (i + 1);
        ll avg2 = (sum - pre[i]) / (n - i - 1);
        if (abs(avg1 - avg2) < ans) {
            res = (i + 1);
            ans = abs(avg1 - avg2);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cout << findEarliestMonth(arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}