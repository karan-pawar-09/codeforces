/*
author:Karan
created:22.06.2021 21:58:02
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll w,n;
    cin>>w>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<bool> dp(w+1,false);
    dp[0]=true;
    for(ll i=0;i<n;i++) { 
        for(ll j=w;j>=0;j--) {
            if(j>=arr[i]) {
                dp[j]=dp[j-arr[i]]|dp[j];
            }
        }
    }
    ll ans=0;
    for(ll i=w;i>=0;i--) {
        if(dp[i]) {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}