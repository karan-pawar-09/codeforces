/*
authot:Karan
created:09.05.2021 20:01:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+7;
    int n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        arr[i]--;
    }
    vector<vector<ll>> dp(n,vector<ll>(m,0));
    for(int i=0;i<n;i++) { 
        if(i)       
        for(int j=0;j<m;j++) {
            if(j) {
                dp[i][j]=(dp[i-1][j-1]%mod+dp[i][j]%mod)%mod;
            }
            if(j<m-1) {
                dp[i][j]=(dp[i-1][j+1]%mod+dp[i][j]%mod)%mod;
            }
            dp[i][j]=(dp[i][j]%mod+dp[i-1][j]%mod)%mod;
        }
        else {
            for(int j=0;j<m;j++) {
                dp[0][j]=1;
            }
        }
        
        if((arr[i])!=-1) {           
            for(int j=0;j<m;j++) {
                if(j^(arr[i])) {
                    dp[i][j]=0;
                }
            }
        }
    }    
    ll ans=0;
    for(int i=0;i<m;i++) {
        ans=(dp[n-1][i]%mod+ans%mod)%mod;
    }
    cout<<ans%mod<<endl;
}
