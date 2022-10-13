/*
    author:Karan
    created:19.08.2022 17:39:43
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
    int q;
    cin>>q;
    vector<int> dp(110, 0);
    dp[0]=1;
    for(int i=0;i<=100;i++) {
        dp[i+3] += dp[i];
        dp[i+1] +=dp[i];
    }
    while(q--) {
        int n;
        cin>>n;
        cout<<dp[n]<<endl;
    }
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