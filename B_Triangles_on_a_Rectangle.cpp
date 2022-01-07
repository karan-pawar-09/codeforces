/*
    author:Karan
    created:18.12.2021 21:36:02
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
    ll w,h;
    cin>>w>>h;
    vector<vector<ll>> arr(4);
    ll k,a;
    for(ll i=0;i<4;i++) {
        cin>>k;
        while(k--) {
            cin>>a;
            arr[i].push_back(a);
        }
    }
    ll ans=0;
    for(ll i=0;i<4;i++) {
        sort(all(arr[i]));
        if(i<2)
            ans=max(ans,abs(arr[i][0]-arr[i][arr[i].size()-1])*h);
        else 
            ans=max(ans,abs(arr[i][0]-arr[i][arr[i].size()-1])*w);
    }
    cout<<ans<<endl;
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