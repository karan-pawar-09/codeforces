/*
author:Karan
created:15.06.2021 17:19:49
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const int mx=3e3+7;
ll a[mx];
ll dp[mx][mx];

ll solve(ll l,ll r) {
    if(l>r) {
        return 0;
    }
    if(l==r) {
        return a[l];
    }
    if(dp[l][r]!=-1) {
        return dp[l][r];
    }
    dp[l][r]=max(min(a[l]-a[l+1]+solve(l+2,r),a[l]-a[r]+solve(l+1,r-1)),min(a[r]-a[r-1]+solve(l,r-2),a[r]-a[l]+solve(l+1,r-1)));
    return dp[l][r];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            dp[i][j]=-1;
        }
    }
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<solve(0,n-1)<<endl;
}