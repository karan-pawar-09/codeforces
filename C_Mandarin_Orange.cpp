#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    int ans=0;
    for(int i=0;i<n;i++) {
        int mini=arr[i];
        for(int j=i;j<n;j++) {
            if(arr[j]<mini) {
                mini=arr[j];
            }
            dp[i][j]=mini*(j-i+1);
            if(dp[i][j]>ans) {
                ans=dp[i][j];
            }
        }
    }
    cout<<ans<<endl;
}