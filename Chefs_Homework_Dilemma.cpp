/*
author:Karan
created:24.07.2021 15:42:42
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
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin>>arr[i];
        vector<ll> dp(n+1,0);
        for(int i=1;i<=n;i++) {
            dp[i]=arr[i-1]+*min_element(dp.begin()+max(0LL,i-k-1),dp.begin()+i-1);
        }
        cout<<*min_element(dp.end()-k-1,dp.end())<<endl;
    }
}