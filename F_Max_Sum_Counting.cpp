/*
    author:Karan
    created:07.09.2021 22:58:33
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=998244353;

ll add(ll a,ll b) {
    return (a+b)%mod;
}
void solve() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first;
    }
    for(ll i=0;i<n;i++) {
        cin>>arr[i].second;
    }
    sort(all(arr));
    vector<ll> dp(50007,0);
    dp[0]=1;
    ll ans=0;
    for(ll i=0;i<=n;i++) {
        for(ll j=0;j<=arr[i].first-arr[i].second;j++) {
            ans= add(ans,dp[j]);
        }
        for(ll j=5000;j>=arr[i].second; --j) {
            dp[j]= add(dp[j],dp[j-arr[i].second]);
        }
    }
    cout<<ans%mod<<endl;
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