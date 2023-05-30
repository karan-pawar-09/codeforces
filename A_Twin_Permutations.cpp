/*
    author:Karan
    created:28.05.2023 20:06:42
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
    cin >> n;
    vector<ll> arr(n);
    ll maxi = 0;
    ll mini = 1e9+10;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        maxi= max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }
    for(ll i=0;i<n;i++) {
        cout<<mini+maxi-arr[i]<<" ";
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