/*
    author:Karan
    created:01.07.2023 17:30:36
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
    n = 8;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ar = arr;
    sort(all(ar));
    for (int i = 0; i < n; i++) {
        if (ar[i] != arr[i]) {
            cout << "No" << endl;
            return;
        }
        if (ar[i] > 675 || ar[i] < 100) {
            cout << "No" << endl;
            return;
        }
        if (ar[i] % 25) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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