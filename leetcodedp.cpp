
/*
authot:Karan
created:16.05.2021 21:00:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
int dp(int i,int j,vector<int> nums) {
        if(i>j) {
            return 0;
        }
        if(i==j) {
            return nums[i];
        }
        return max((nums[i]+min(dp(i+2,j,nums),dp(i+1,j-1,nums))),(nums[j]+min(dp(i,j-2,nums),dp(i+1,j-1,nums))));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int ans=dp(0,nums.size()-1,nums);
        cout<<ans<<endl;
        int fullsum=0;
        for(int i=0;i<nums.size();i++) {
            fullsum+=nums[i];
        }
        
        if(ans>=fullsum-ans) {
            return true;
        }
        else {
            return false;
        }
    }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums={1,5,2};
    bool ans=PredictTheWinner(nums);
    cout<<ans;
}
/*
authot:Karan
created:16.05.2021 22:53:54
*/
