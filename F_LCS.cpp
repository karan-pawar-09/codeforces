#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int m,n;
    m=a.size();
    n=b.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<m+1;i++) {
        for(int j=1;j<n+1;j++) {
            if(a[i-1]==b[j-1]) {
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }     
        }
    }
    string ans;
    int i=m;
    int j=n;
    while(j!=0&&i!=0) {
        if(dp[i-1][j]==dp[i][j]) {
            i--;
        }
        else if(dp[i][j-1]==dp[i][j]) {
            j--;
        }
        else {
            ans+=a[i-1];
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

