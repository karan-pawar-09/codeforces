/*
author:Karan
created:15.08.2021 22:08:09
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
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> arr(m);
    for(int i=0;i<m;i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    vector<int> dp(m+1);
    dp[0]=1;
    for(int i=0;i<m;i++) {
        for(int j=m;j>=0;j--) {
            if(i+arr[j].first<=n) {
                dp[i+arr[j].first]+=dp[i];
                if(i+arr[j].second<=n) {
                    dp[i+arr[j].second]-=dp[i];
                }
            }
        }
    }
    for(int i=1;i<=m;i++) {
        dp[i]=dp[i]+dp[i-1];
    }
    int sum=0;
    for(int i=0;i<n;i++) {
        sum+=dp[i];
    }
    cout<<sum<<endl;
}