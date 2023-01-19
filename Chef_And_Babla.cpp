/*
    author:Karan
    created:18.01.2023 20:10:24
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

bool isGood(ll k, vector<ll> &arr) {
    for(auto x: arr) {
        if((x >= -k) && (x <= k)) {
            return false;
        }
    }
    return true;
}
ll binarysearch(vector<ll> &arr) {
    ll l = 0;
    ll r = 1e18+10;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(isGood(m, arr)) {
            l = m;
        } else {
            r = m;
        }
    }
    if(!isGood(l, arr)) {
        return -1;
    } else {
        return l;
    }
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<binarysearch(arr)<<endl;
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