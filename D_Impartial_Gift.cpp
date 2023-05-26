/*
    author:Karan
    created:25.05.2023 13:06:37
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

ll bs1(vector<ll> &arr, ll p, ll d) {
    ll r = arr.size();
    ll l = 0;
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(arr[m] <= p) {
            l = m;
        } else {
            r = m;
        }
    }
    if(arr[l] <= p && p-arr[l] <= d) {
        return arr[l];
    } else {
        return -2e18-10;
    }
}

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    vector<ll> b(m);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<m;i++) {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    ll maxi = -1;
    for(ll i=0;i<n;i++) {
        maxi = max(maxi, bs1(b, a[i], d)+a[i]);
    }
    for(ll i=0;i<m;i++) {
        maxi = max(maxi, bs1(a, b[i], d)+b[i]);
    }
    cout<<maxi<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
   
    while(t--) {
        solve();
    }
}