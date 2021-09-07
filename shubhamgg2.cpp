/*
author:Karan
created:09.07.2021 23:30:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int mx=2*abs(target)+7;
    vector<vector<int>> sum(n+2,vector<int> (mx,0));
    int middle=abs(target)+2;
    sum[0][middle]=1;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<mx;j++) {
            if(j+nums[i-1]<mx)
                sum[i][j]+=sum[i-1][j+nums[i-1]];
            if(j-nums[i-1]>=0)
                sum[i][j]+=sum[i-1][j-nums[i-1]];

            sum[i][j]=max(sum[i][j],sum[i-1][j]);
        }
    }
    return sum[n][middle+target];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,target;
    cin >>n>>target;
    vector<int> nums(n); 
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    cout<<findTargetSumWays(nums,target);
}