/*
author:Karan
created:27.07.2021 11:12:38
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        for (auto& i : a) --i;

        vector<vector<int>> dp(n + 1, vector<int>(n, (int)-1e9));
    
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int cnt = 0; cnt < n; ++cnt) {
                dp[i][cnt]=max(dp[i][cnt], dp[i-1][cnt] + (a[i-1] == i - cnt-1));
                if (cnt>0&&dp[i-1][cnt-1]>=0) {
                    dp[i][cnt]=max(dp[i][cnt ], dp[i-1][cnt-1]);
                }
            }
        }
       
        int ans = -1;
        for (int cnt = 0; cnt < n; ++cnt) {
            if (dp[n][cnt] >= k) {
                ans=cnt;
                break;
            }
        }
        cout<<ans<<endl;
    }
}