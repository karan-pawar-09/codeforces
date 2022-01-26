/*
    author:Karan
    created:20.01.2022 22:36:49
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
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(m+1);
    arr[0]=1;
    for(ll i=1;i<=m;i++) {
        cin>>arr[i];
    }
    ll res=0;
    for(ll i=1;i<=m;i++) {
        if(arr[i]>=arr[i-1]) {
            res+=arr[i]-arr[i-1];
        } else {
            res+=arr[i]+n-arr[i-1];
        }
    }
    cout<<res<<endl;
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