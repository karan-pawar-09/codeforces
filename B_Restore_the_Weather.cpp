/*
    author:Karan
    created:19.06.2023 20:49:59
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        arr[i].first = a[i];
        arr[i].second = i;
    }
    sort(all(arr));
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(all(b));
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[arr[i].second] = b[i];
    }
    for(auto x: ans) cout<<x<<" ";
    cout<<endl;

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