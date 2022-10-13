/*
    author:Karan
    created:03.08.2022 21:43:56
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

ll ceil(ll a, ll b) {
    return (a+b-1)/b;
}

void solve() {
    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> arr(n);
    ll maxi = -1;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        maxi = max(maxi, arr[i]);
    }
    if(y>=x) {
        cout<<ceil(maxi,y)<<endl;
    } else {
        ll stored = 0;
        ll ans = 0;
        for(ll i=n-1;i>=0;i--) {
            if((arr[i]-stored)>0) {
                ll req = ceil(arr[i]-stored, x);
                ans += req;
                stored += req*y;
            }
        }
        cout<<ans<<endl;
    }
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