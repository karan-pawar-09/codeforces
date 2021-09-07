/*
author:Karan
created:01.09.2021 22:05:14
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

template<ll D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template<typename... Args>
  Vec(ll n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {
  }
};
template<typename T>
struct Vec<1, T> : public vector<T> {
  Vec(ll n = 0, const T& val = T()) : vector<T>(n, val) {
  }
};
// Vec<3,ll> dp (n,n,K+1,-inf); makes 3d vector of size n,n,k+1 and fill with -inf;

const ll inf=(ll)1e18+7;

void solve() {
    ll n,K;
    cin>>n>>K;
    vector<string> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<vector<ll>> price(n,vector<ll> (n));
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            cin>>price[i][j];
        }
    }

    Vec<3,ll> dp (n,n,K+1,-inf);

    dp[0][0][0]=price[0][0];

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            for(ll k=0;k<=K and i!=0;k++) {
                if(k!=0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]+price[i][j]);
                }
                if(((k==0) or (k==K)) and arr[i][j]=='.') {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]+price[i][j]);
                }
            } 
            for(ll k=0; k<=K and j!=0; k++) {
                if(k!=0) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]+price[i][j]);
                }
                if((k==0 or k==K) and arr[i][j]=='.') {
                    dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]+price[i][j]);
                }
            }
        }
    }
    ll ans=-inf;
    for(auto x:dp[n-1][n-1]) {
        ans=max(ans,x);
    }
    (ans>0) ? cout<<ans<<endl : cout<<-1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}