/*
    author:Karan
    created:12.03.2022 22:44:54
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

ll binarysearch(ll a, vector<ll>& arr, ll n) {
    ll l = -1;
    ll r = n - 1;
    while (l + 1 < r) {
        ll m = l + (r - l) / 2;
        if (arr[m] >= a) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return r;
}
int findLIS(vector<int> arr) {
    int n = arr.size();
    vector<ll> ans;
    ans.push_back(arr[0]);
    for (ll i = 1;i < n;i++) {
        if (arr[i] > ans.back()) {
            ans.push_back(arr[i]);
        }
        else {
            if (ans.back() != arr[i]) {
                ans[binarysearch(arr[i], ans, ans.size())] = arr[i];
            }
        }
    }
    return ans.size();
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    cout << findLIS(arr) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    while (t--) {
        solve();
    }
}