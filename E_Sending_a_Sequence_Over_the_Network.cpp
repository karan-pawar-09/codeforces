/*
    author:Karan
    created:11.10.2022 21:51:00
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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int i=1;i<=n;i++) {
        if(dp[i-1] != -1) {
            if((i+arr[i]) <= n) {
                dp[i+arr[i]] = dp[i-1]+1;
            }
        }
        if((i-arr[i]-1) >= 0) {
            if(dp[i-arr[i]-1] != -1) {
                dp[i] = dp[i-arr[i]-1] +1;
            }
        }
    }
    (dp[n] != -1) ? cout<<"YES"<<endl: cout<<"NO"<<endl;
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