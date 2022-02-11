/*
    author:Karan
    created:31.01.2022 22:53:39
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



int dp[(int)1e3+10];

void solve() {
    int n,x;
    cin>>n>>x;
    int res=0;
    vector<int> b(n),c(n);
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    for(int i=0;i<n;i++) {
        cin>>c[i];
    }
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        a[i]=dp[b[i]];
    }   
    vector<int> ans(x+1,0);
    for(int i=0;i<n;i++) {
        for(int j=x;j>=0;j--) {
            if(j-a[i]>=0) {
                ans[j]=max(ans[j],ans[j-a[i]]+c[i]);
            }
        }
    } 
    cout<<ans[x]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int N=1e3;
    std::fill(dp, dp + N + 1, 1E9);
    dp[1]=0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i + i / j <= N) {
                dp[i + i / j] = std::min(dp[i + i / j], dp[i] + 1);
            }
        }
    }
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}