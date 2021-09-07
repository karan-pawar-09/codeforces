#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

vector<vector<ll>> dp;
vector<ll> arr;
ll solve(ll l, ll r,ll n) {
    if(l==r) {
        return 0;
    }
    else if(l==n||r==-1) {
        return (ll)1e18;
    }
    else if(dp[l][r]!=-1) {
        return dp[l][r];
    }
    dp[l][r]=abs(arr[l]-arr[r])+min(solve(l+1,r,n),solve(l,r-1,n));
    return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;    
    arr=vector<ll>(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];    
    }
    sort(all(arr));   
    dp=vector<vector<ll>>(n+2,vector<ll> (n+2,-1));
    ll ans=solve(0,n-1,n);
    cout<<ans<<endl;
}   