/*
    author:Karan
    created:08.07.2023 11:20:02
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
    vector<int> arr(n);
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        count[arr[i]]++;
    }
    cout << "- 0" << endl;;
    cout.flush();
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    int ct = 0;
    while (t--) {
        solve();
    }
}