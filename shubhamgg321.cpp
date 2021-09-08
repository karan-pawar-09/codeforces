/*
    author:Karan
    created:08.09.2021 08:12:50
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll binarysearch(vector<ll> &arr,ll a,int i) {
    ll n=arr.size();
    ll l=0;
    ll r=i;
    while(l+1<r) {
        ll m=(l+(r-l)/2);
        if(arr[m]<a) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return l;
}
void solve() {
    ll m,n;
    cin>>m;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    vector<ll> a(n),b(n);
    vector<ll> ar(n+1,0);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        ar[i+1]=a[i];
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
    }
    ar[0]=-(1e18);
    ll t;
    cin>>t;
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    dp[0][0]=b[0];
    dp[0][1]=0;
    for(ll i=1;i<n;i++) {
        ll indx=binarysearch(ar,a[i]-t,i+1);
        
        if(indx>=1)
            dp[i][0]=max(dp[indx-1][0],dp[indx-1][1])+b[i];
        dp[i][0]=max(dp[i][0],b[i]);
        dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
    }
    
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}