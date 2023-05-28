/*
    author:Karan
    created:27.05.2023 17:35:04
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
    set<pair<int, int>> s;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            s.insert({i, j});
        }
    }
    vector<vector<int>> arr(m, vector<int> (n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++) {
        for(int j=1;j<n;j++) {
            s.erase({min(arr[i][j-1], arr[i][j]), max(arr[i][j-1], arr[i][j])});
        }
    }
    cout<<s.size()<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}