/*
author:Karan
created:06.06.2021 18:12:43
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll sum=0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        sum+=arr[i];
    }  
    sort(all(arr));
    ll ans=(ll)1e8;
    vector<bool> dp(sum+1,false);
    dp[0]=true;
    for(ll j=0;j<n;j++) {
        for(ll i=sum;i>=0;i--) {        
            if(dp[i]&&i+arr[j]<=sum) {
                dp[i+arr[j]]=true;
            }
        }
    } 
    for(ll i=0;i<=sum;i++) {
        if(dp[i]) {
            ans=min(ans,max(sum-i,i));
        }
    }
    cout<<ans<<endl;
    // cout<<max(dp[n][0],dp[n][1])<<endl;
}