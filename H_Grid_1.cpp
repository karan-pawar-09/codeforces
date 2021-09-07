#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = (int)1e9+7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<char>> arr(h,vector<char>(w));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>dp(h+1,vector<int>(w+1,0));
    dp[1][1]=1;
    for(int i=1;i<=h;i++) {
        for(int j=1;j<=w;j++) {
            if(arr[i-1][j-1]!='#') {
                if(i!=1||j!=1)
                dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
    }
    cout<<dp[h][w]%mod<<endl;
}

