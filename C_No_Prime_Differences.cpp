/*
    author:Karan
    created:04.06.2023 21:57:55
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
    vector<vector<int>> arr(n, vector<int>(m, -1));
    int temp = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            arr[i][j] = temp;
            temp++;
        }
    }
    if(n%2 && m%2) {
        for(int i = 0; i < n  ; i += 2) {
            for(auto x:arr[i]) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        for(int i = 1; i < n; i+= 2) {
            for(auto x: arr[i]) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        // for(auto x: arr[n-1]) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
    } else {
        if(m % 2) {
            temp = 1;
            for(int j = 0; j < m; j++) {
                for(int i = 0; i < n; i++) {
                    arr[i][j] = temp;
                    temp++;
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
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