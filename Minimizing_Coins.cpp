#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<int> dp(x+1,1e6+7);
    dp[0]=0;
    for(int i=0;i<n;i++) {
        for(int j=1;j<=x;j++) {
            if(j-arr[i]>=0) {
                dp[j]=min(dp[j-arr[i]]+1,dp[j]);
            }
        }
    }
    dp[x]==(int)1e6+7?cout<<"-1"<<endl:cout<<dp[x]<<endl;
}