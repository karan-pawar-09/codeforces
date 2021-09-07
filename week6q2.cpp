/*
author:Karan
created:22.06.2021 22:11:21
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
    ll n,w;
    w=0;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        w+=arr[i];
    }
    sort(all(arr));
    vector<bool> dp(w+1,false);
    dp[0]=1;
    for(ll i=0;i<n;i++) {
        for(ll j=w;j>=0;j--) {
            if(j>=arr[i]) {
                dp[j]=dp[j]|dp[j-arr[i]];
            }
        }
    }
    if(dp[w]&&dp[(2*w)/3]&&dp[w/3]&&(w%3==0)) {
        cout<<1<<endl;
    }
    else {
        cout<<0<<endl;
    }
}