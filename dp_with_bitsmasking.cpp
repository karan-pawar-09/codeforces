/*
author:Karan
created:22.08.2021 16:48:22
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<int>> dp;
vector<vector<int>> arr;

int solve(int i,int mask,int &n) {
    if(i==n) return 0;
    if(dp[i][mask]!=-1) {
        return dp[i][mask];
    }
    int answer=1e9+7;
    for(int j=0;j<n;j++) {
        if(mask&(1<<j)) {
            answer=min(answer,arr[j][i]+solve(i+1,mask^((1<<j)),n));
        }
    }
    return dp[i][mask]=answer;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    arr.resize(n,vector<int> (n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    dp.resize(n,vector<int> ((1<<n),-1));
    cout<<solve(0,(1<<n)-1,n)<<endl;
}