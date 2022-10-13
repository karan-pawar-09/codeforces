/*
    author:Karan
    created:14.08.2022 14:30:08
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

int inf = 1e9+10;

int find(int x) {
    vector<int> dp(x+10, inf);
    dp[0]=0;
    for(int i=0;i<=x;i++) {
        dp[i+2]=min(dp[i+2],dp[i]+1);
        dp[i+3]=min(dp[i+3],dp[i]+1);
    }
    return dp[x];
}
void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int, int> M;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        M[arr[i]]++;
    }
    vector<int> ar;
    for(auto x: M) {
        ar.push_back(x.second);
    }
    int res = 0;
    for(auto x: ar) {
        int k = find(x);
        if(k == inf) {
            res = -1;
            break;
        }
        res += k;
    }
    cout<<res<<endl;
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