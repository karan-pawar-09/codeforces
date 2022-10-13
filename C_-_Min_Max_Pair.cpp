/*
    author:Karan
    created:31.07.2022 17:42:30
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
    vector<ll> arr(n+1);
    ll inplace = 0;
    for(ll i = 1; i<= n; i++) {
        cin>>arr[i];
        if(arr[i]!=(i)) {
        
        } else {
            inplace++;
        }
    }
    ll pairs=0;
    for(ll i=1;i<=n;i++) {
        if(arr[i] > i ) {
            if(i == arr[arr[i]]) {
                pairs++;
            }
        }
    }
    ll ans = pairs;
    ans+=(inplace*(inplace-1))/2;
    cout<< ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}