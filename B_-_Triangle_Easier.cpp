/*
    author:Karan
    created:31.07.2022 17:36:42
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
    int n, m, u, v;
    cin >> n >> m;
    vector<set<int>> arr(n+1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(arr[i].find(j) != arr[i].end()) {
                for(int k = j+1; k <= n; k++) {
                    if(arr[j].find(k) != arr[j].end()) {
                        if(arr[k].find(i) != arr[k].end()) {
                            ans++;
                        }
                    }
                }
            }
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
    while(t--) {
        solve();
    }
}