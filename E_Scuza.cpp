/*
    author:Karan
    created:13.10.2022 20:30:16
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

ll binarysearch(vector<ll> &arr, ll x) {
    ll l = 0;
    ll r = arr.size();
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(arr[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    if(arr[l] <= x) {
        return l;
    } else {
        return -1;
    }
}
void solve() {
    ll n, q;
    cin>>n>>q;
    vector<ll> arr(n);
    vector<ll> pre(n, 0);
    vector<ll> ar(n);
    for(ll i =0;i<n;i++) {
        cin>>arr[i];
        if(i==0) {
            ar[i] = arr[i];
            pre[i] = arr[i];
        } else {
            ar[i] = max(arr[i], ar[i-1]);
            pre[i] = arr[i] + pre[i-1];
        }
    }

    while(q--) {
        ll a;
        cin>>a;
        ll ans = binarysearch(ar, a);
        if(ans == -1) {
            cout<<0<<" ";
        } else {
            cout<<pre[ans]<<" ";
        }
    }
    cout<<endl;
    
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