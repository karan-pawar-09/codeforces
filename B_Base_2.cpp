/*
    author:Karan
    created:17.06.2023 17:31:42
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
    vector<ll> arr(64);
    unsigned ll res = 0;
    unsigned ll p = 1;
    for(ll i = 0; i < 64; i++) {
        cin >> arr[i];
        res += arr[i] * p;
        p *= 2LL;
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