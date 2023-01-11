/*
    author:Karan
    created:07.01.2023 20:05:50
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

int ans(int len, int arr[]) {
    int res = 0;
    int dp[len+1];
    for(int i=0;i<=len;i++) {
        dp[i] = 0;
    }
    int n = sizeof(arr)/sizeof(*arr);
    for(int j=0;j<=len;j++) {
        for(int i=1;i<n;i++) {
            if(j+i <= len) {
                dp[j+i] = max(dp[j+i], dp[j]+arr[i]);
            }
        }
    }
    return dp[len];
}
void solve() {
    int len, n;
    cin>>len>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<ans(len, arr)<<endl;
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