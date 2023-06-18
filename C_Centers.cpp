/*
    author:Karan
    created:17.06.2023 17:42:31
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
    vector<int> arr(3 * n);
    vector<pair<int, int>> ar(n);
    for(int i = 0; i < n; i++) {
        ar[i].second = i+1;
    }
    vector<bool> used(n, false);
    for(int i = 0; i < (3 * n); i++) {
        cin >> arr[i];
        if(used[arr[i]]) {
            ar[arr[i]-1].first = i;
            used[arr[i]] = false;
        } else {
            used[arr[i]] = true;
        }
    }
    
    sort(all(ar));
    for(auto x: ar) {
        cout<<x.second<<" ";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    while(t--) {
        solve();
    }
}