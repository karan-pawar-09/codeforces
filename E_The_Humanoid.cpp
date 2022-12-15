/*
    author:Karan
    created:25.11.2022 13:39:56
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
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    vector<vector<int>> dp(n, vector<int> (3, 0));
    vector<vector<pair<int, int>>> rem(n, vector<pair<int, int>> (3, {0, 0}));
    dp[0][0]= h;
    rem[0][0] = {2, 1};
    dp[0][1] = h*2;
    rem[0][1] = {1, 1};
    dp[0][2] = h*3;
    rem[0][2] = {2, 0};
    for(int i=0;i<n;i++) {
        {
            if(dp[i][0] > arr[i]) {
                dp[i+1][0] = dp[i][0]+(arr[i-1]/2);
            } else {
                dp[i+1][0] = 
            }
        }
        {

        }
        {

        }
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