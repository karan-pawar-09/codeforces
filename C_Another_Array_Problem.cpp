/*
    author:Karan
    created:31.12.2022 00:22:11
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
    ll maxelement = 0, minelement = 1e9+10, sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        maxelement = max(maxelement, arr[i]);
        minelement = min(minelement, arr[i]);
    }
    if(n == 2) {
        cout << max(arr[0]+arr[1], abs(arr[0] - arr[1]) * 2)<<endl;
        return;
    }
    if(n == 3) {
        cout << max({3 * arr[0],3 * arr[2],3 * abs(arr[0]- arr[1]),3 * abs(arr[2] - arr[1]) ,sum}) << endl;
        return;
    }
    cout << maxelement * n << endl;
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