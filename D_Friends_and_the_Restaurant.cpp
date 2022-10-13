/*
    author:Karan
    created:15.09.2022 00:14:45
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
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        b[i] -= a[i];
    }
    sort(all(b));
    int l = 0;
    int r = n-1;
    int ans = 0;
    // for(auto x: b) cout << x << " ";
    // cout << endl;
    while(l < r) {
        if(-b[l] <= b[r]) {
            ans ++;
            l++;
            r--;
        } else {
            l++;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}