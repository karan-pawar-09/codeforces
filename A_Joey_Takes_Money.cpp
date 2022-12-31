/*
    author:Karan
    created:01.01.2023 00:31:17
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
    ll mul = 1;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        mul *= arr[i];
    }
    mul += n-1;
    cout << mul * 2022 << endl;

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