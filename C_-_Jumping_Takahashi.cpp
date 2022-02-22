/*
    author:Karan
    created:20.02.2022 17:36:18
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
    int n,x;
    cin>>n>>x;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    vector<bool> dp(x+10,false);
    dp[0]=true;
    bool ans=false;
    for(int i=0;i<n;i++) {
        for(int j=x;j>=0;j--) {
            if(dp[j]) {
                dp[j]=false;
                if(j+arr[i].first<=x) {
                    dp[j+arr[i].first]=true;
                    if((i==n-1) and ((j+arr[i].first)==x)) {
                        ans=true;
                    }
                }
                if(j+arr[i].second<=x) {
                    dp[j+arr[i].second]=true; 
                    if((i==n-1) and ((j+arr[i].second)==x)) {
                        ans=true;
                    }
                }
            }
        }
    }
    ans?cout<<"Yes"<<endl:cout<<"No"<<endl;
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