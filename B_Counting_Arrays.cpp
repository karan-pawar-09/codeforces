/*
    author:Karan
    created:07.11.2021 17:31:37
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
    set<vector<ll>> s;
    for(ll i=0;i<n;i++) {
        ll k;
        cin>>k;
        vector<ll> arr(k);
        for(ll j=0;j<k;j++) {
            cin>>arr[j];
        }
        s.insert(arr);
    }
    cout<<s.size()<<endl;
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