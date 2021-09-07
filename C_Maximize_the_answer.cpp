#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,a,b;
        cin>>n>>a>>b;
        vector<ll> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<vector<ll>> kp(3,vector<ll> (n));
        for(int i=0;i<n;i++)    {
            kp[0][i]=a*arr[i];
            kp[1][i]=b*arr[i];
            kp[2][i]=arr[i];
        }
        vector<vector<ll>> dp(3,vector<ll> (n,0));
        for(int i=1;i<n;i++) {
            for(int j=0;j<3;j++) {
                for(int k=0;k<3;k++) {
                    dp[j][i]=max((dp[k][i-1]+abs(kp[k][i-1]-kp[j][i])),dp[j][i]);
                }
            }
        }
        cout<<max({dp[0][n-1],dp[1][n-1],dp[2][n-1]})<<endl;
    }
}