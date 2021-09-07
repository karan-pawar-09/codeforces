#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INFI = 1e9+5;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<int>dp(n,INFI);
    dp[0]=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<=i+k;j++) {
            if(j<n) {
                dp[j]=min(dp[j],dp[i]+abs(arr[j]-arr[i]));
            }
        }
    }
    cout<<dp[n-1]<<endl;
}