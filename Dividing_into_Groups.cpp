/*
    author:Karan
    created:31.05.2023 20:45:37
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


bool isGood(ll res, vector<ll> &arr, ll k) {
    ll sum = 0;
    for(auto x: arr) {
        sum += min(res, x);
    }
    return (sum/k) >= (res);
}

ll binarysearch(vector<ll> &arr, ll k) {
    ll l = 0;
    ll r = 1e18+10;
    while(l+1 < r) {
        ll mid = l+(r-l)/2;
        if(isGood(mid, arr, k)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr), greater<ll>());
    cout<<binarysearch(arr, k)<<endl;
    
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