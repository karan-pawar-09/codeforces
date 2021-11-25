/*
    author:Karan
    created:17.11.2021 00:08:11
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
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    ll l=0;
    ll r=1e18/k;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        ll sum=0;
        for(auto x:arr) {
            sum+=min(x,m);
        }
        if((m*k)<=sum) {
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<l<<endl;
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