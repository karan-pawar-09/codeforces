/*
    author:Karan
    created:11.03.2022 13:04:45
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
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int> > arr(m);
    int a, b;
    for (int i = 0;i < m;i++) {
        cin >> arr[i].first.second;
        cin >> arr[i].first.first;
        arr[i].second = i + 1;
    }
    sort(all(arr));
    vector<pair<pair<int, int>, int> > ar;
    int sum = 0;
    for (int i = 0;i < 2 * n;i++) {
        ar.push_back(arr[i]);
        ar[i].first.first = arr[i].first.second;
        ar[i].first.second = arr[i].first.first;
        sum += arr[i].first.first;
    }
    sort(all(ar));
    cout << sum << endl;
    for (int i = 0;i < n;i++) {
        cout << ar[i].second << " " << ar[(2 * n) - 1 - i].second << endl;
    }
    cout << endl;
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