/*
    author:Karan
    created:20.01.2023 09:52:55
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

ll binarysearch(vector<ll> &arr, ll k) {
    ll l = 0;
    ll r = arr.size();
    while(l+1 < r) {
        ll m = (l+r)/2;
        if(arr[m] < k) {
            l = m;
        } else {
            r = m;
        }
    }
    if(arr[l] >= k) {
        return -1;
    }
    return l;
}

void solve() {
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    for(ll i=0;i<n;i++) {
        cin>> a[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(a));
    ll maxi = 0;
    for(ll i=0;i<m;i++) {
        ll j = i+1;
        ll prev = -1;
        ll cur = -1;
        ll res = 0;
        for(; j <= (m) ; j+= (i+1) ) {
            prev = cur;
            cur = binarysearch(a, j);
            res += (cur - prev) * ((j/(i+1)) -1); 
        }
        prev = cur;
        cur = binarysearch(a, j);
        res += (cur-prev) * ((j/(i+1)) -1);
        res *= b[i];
        maxi = max(maxi, res);
    }
    cout<<maxi<<endl;
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