/*
    author:Karan
    created:21.08.2022 17:40:36
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

const int mod = 1e9+7;
int add(int a, int b) {
    return ((a%mod)+(b%mod))%mod;
}
void solve() {
    int n, x, k;
    cin>>n>>k>>x;
    vector<vector<int>> dp(n+1, vector<int> (k+1));
    for(int i=1;i<=k;i++) {
        dp[0][i] = 1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            if(j==x) {
                for(int p=1;p<=k;p++) {
                    dp[i][j] = add(dp[i][j], dp[i-1][p]);
                }
            } 
            else {
                for(int p = 1;p<=k;p++) {
                    if(p!=j) {
                        dp[i][j] = add(dp[i][j], dp[i-1][p]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=k;i++) {
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;
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