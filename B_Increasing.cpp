/*
    author:Karan
    created:13.10.2022 20:07:55
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
    vector<ll> arr(n);
    bool ans = true;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    for(ll i=1;i<n;i++) {
        if(arr[i] == arr[i-1]) {
            ans = false;
            break;
        }
    }
    ans? cout<<"YES"<<endl: cout<<"NO"<<endl;
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