/*
    author:Karan
    created:21.06.2023 20:22:04
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
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr), greater<ll>());
    ll maxi = arr[0];
    ll size = 1;
    for(ll i = 1; i < n; i++) {
        if(maxi >= arr[i]) {
            maxi ^= arr[i];
        } else {
            size++;
            maxi = arr[i];
        }
    }
    cout<<size<<endl;
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