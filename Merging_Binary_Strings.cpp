/*
    author:Karan
    created:19.01.2022 21:45:56
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

void solve() {
    ll n;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    vector<vector<ll>> arr(n+1,vector<ll> (n+1,0));
    vector<vector<ll>> dp(n+1,vector<ll> (n+1,0));
    for(ll i=1;i<=n;i++) {
        if(s[i-1]=='1') {
            arr[0][i]=arr[0][i-1]+1;
        } else {
            arr[0][i]=arr[0][i-1];
        }
    }
    for(ll i=1;i<=n;i++) {
        if(t[i-1]=='1') {
            arr[i][0]=arr[i-1][0]+1;
        } else {
            arr[i][0]=arr[i-1][0];
        }
    }
    for(ll i=1;i<=n;i++) {
        ll x=0;
        if(t[i-1]=='1') x=1;
        for(ll j=1;j<=n;j++) {
            ll y=0;
            if(s[j-1]=='1') {
                y++;
            }
            arr[i][j]=arr[i-1][j-1]+x+y;
        }
    }
    for(ll i=1;i<=n;i++) {
        if(s[i-1]=='0') {
            dp[0][i]=arr[0][i-1]+dp[0][i-1];
        } else {
            dp[0][i]=dp[0][i-1];
        }
    }
    for(ll i=1;i<=n;i++) {
        if(t[i-1]=='0') {
            dp[i][0]=arr[i-1][0]+dp[i-1][0];
        } else {
            dp[i][0]=dp[i-1][0];
        }
    }
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=n;j++) {
            ll k=0;
            ll p=0;
            if(s[j-1]=='0') {
                k=arr[i][j-1]+dp[i][j-1];
            } else {
                k=dp[i][j-1];
            }
            if(t[i-1]=='0') {
                p=arr[i-1][j]+dp[i-1][j];
            } else {
                p=dp[i-1][j];
            }
            dp[i][j]=min(p,k);
        }
    }
    cout<<dp[n][n]<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}