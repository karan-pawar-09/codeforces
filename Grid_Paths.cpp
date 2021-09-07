#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+7;
    int n;
    cin>>n;
    vector<vector<char>> arr(n,vector<char> (n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    vector<vector<ll>> dp((n+1),vector<ll> ((n+1),0));
    dp[1][1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {            
            if(i==1&&j==1) {
               
            }  
            else {
                dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }     
            if(arr[i-1][j-1]=='*') {
                dp[i][j]=0;
            }     
        }
    }
    cout<<dp[n][n]%mod<<endl;
}
