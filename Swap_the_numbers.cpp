/*
    author:Karan
    created:28.06.2023 20:06:22
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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    vector<ll> dp(n, true);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(i - k < 0 && i+k >= n) {
            dp[i] = false;
        }
    }
    vector<ll> ar1;
    vector<ll> ar2;
    for(ll i = 0; i < n; i++) {
        if(dp[i]) {
            ar1.push_back(arr[i]);
        } else {
            ar2.push_back(arr[i]);
        }
    }
    sort(all(ar1));
    ll inx = 0;
    ll indx = 0;
    for(ll i = 0; i < n; i++) {
        if(dp[i]) {
            cout<<ar1[indx++]<<" ";
        } else {
            cout<<ar2[inx++]<<" ";
        }
    }
    cout<<endl;
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