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
    ll mod=(ll)1e9+7;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<ll> dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++) {
        for(int j=0;j<n;j++) {
            if(i>=arr[j]) {
                dp[i]+=dp[i-arr[j]];
                dp[i]%=mod;
            }
        }
    } 
    cout<<dp[x]<<endl;
}