#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

// long long getWays(int n, vector<long long> c) {
//     vector<vector<long long>> dp(c.size()+1,vector<long long>(n+1,0));
//     for(int i=0;i<=c.size();i++) {
//         dp[i][0]=1;
//     }
//     for(int i=1;i<=c.size();i++) {
//         for(int j=1;j<n+1;j++) {
//             if(c[i-1]<=j) {
//                 dp[i][j]=dp[i-1][j]+dp[i][j-c[i-1]];
//             }
//             else {
//                 dp[i][j]=dp[i-1][j];
//             }
//         }
//     }
//     return dp[c.size()][n];
// }
long long getWays(int n, vector<long long> c) {
    vector<ll> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=c.size();i++) {
        for(int j=1;j<n+1;j++) {
            if(c[i-1]<=j) {
                dp[j]=dp[j]+dp[j-c[i-1]];
            }
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<ll> arr(m);
    for(ll i=0;i<m;i++) {
        cin>>arr[i];
    }
    ll ans=getWays(n,arr);
    cout<<ans<<endl;
}
