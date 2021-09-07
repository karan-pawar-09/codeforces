/*
author:Karan
created:21.06.2021 23:52:46
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
    ll n,l,m;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    cin>>m;
    vector<ll> b(m);
    for(ll i=0;i<m;i++) {
        cin>>b[i];
    }
    cin>>l;
    vector<ll> c(m);
    for(ll i=0;i<l;i++) {
        cin>>c[i];
    }
    ll dp[n+1][m+1][l+1];
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=m;j++) {
            for(ll k=0;k<=l;k++) {
                dp[i][j][k]=0;
            }
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=m;j++) {
            for(ll k=1;k<=l;k++) {
                if((a[i-1]==b[j-1])&&(b[j-1]==c[k-1])) {
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else{
                    dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1],dp[i-1][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1]});
                }
            }
        }
    }
    cout<<dp[n][m][l]<<endl;
}   