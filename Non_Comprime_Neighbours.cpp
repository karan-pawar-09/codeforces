/*
    author:Karan
    created:23.02.2022 22:34:17
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
    vector<ll> arr(n+100,1);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    for(int i=1;i<(n+10);i+=3) {
        arr[i-1]=2*arr[i];
        arr[i+1]=2*arr[i];
    }
    for(ll i=0;i<n;i++) {
        cout<<arr[i]<<" ";
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