/*
    author:Karan
    created:04.01.2022 19:52:53
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

int cherryPickup(vector<vector<int>>& grid) {
    int m = (int)grid.size(), n = (grid[0].size());
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n, vector<int>(n, 0)));
    dp[0][0][n - 1] = 0 == n - 1 ? grid[0][0] : grid[0][0] + grid[0][n - 1];
    for (int row = 1; row < m; row++) {
        for (int c1 = 0; c1 < min(n, row + 1); c1++) {
            for (int c2 = max(0, n - 1 - row); c2 < n; c2++) {
                int prev_max = 0;
                for (int offset1 = max(0, c1 - 1); offset1 <= min(n - 1, c1 + 1); offset1++) {
                    for (int offset2 = max(0, c2 - 1); offset2 <= min(n - 1, c2 + 1); offset2++) {
                            prev_max = max(prev_max, dp[row - 1][offset1][offset2]);
                    }
                }
                if (c1 == c2)
                    dp[row][c1][c2] = prev_max + grid[row][c1];
                else
                    dp[row][c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
            }
        }
    }
    int col = grid[0].size();
    return dp[m-1][0][n-1];
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    cout<<cherryPickup(arr)<<endl;
} 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}