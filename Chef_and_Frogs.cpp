/*
author:Karan
created:29.05.2021 14:50:58
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,p;
    cin>>n>>k>>p;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second=i;
    }
    sort(all(arr));
    vector<ll> dp(n);
    for(ll i=0;i<n;i++) {
        dp[i]=i;
    }
    for(ll i=1;i<n;i++) {
        if(arr[i].first-arr[i-1].first<=k) {
            dp[arr[i].second]=dp[arr[i-1].second];
        }
    }
    while(p--) {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        if(dp[b]==dp[a]) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
}