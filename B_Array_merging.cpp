/*
    author:Karan
    created:28.05.2023 20:18:28
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
    vector<ll> a(n), b(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
    }
    vector<ll> ap(2*n+10), bp(2*n+10);
    ll prev = -1;
    ll count = 0;
    for(ll i=0;i<n;i++) {
        if(a[i]==prev) {
            count++;
        } else {
            count = 1;
        }
        prev = a[i];
        ap[a[i]] = max(ap[a[i]], count);
    }
    prev = -1;
    count = 0;
    for(ll i=0;i<n;i++) {
        if(b[i]==prev) {
            count++;
        } else {
            count = 1;
        }
        prev = b[i];
        bp[b[i]] = max(bp[b[i]], count);
    }
    ll ans = 0;
    for(ll i=0;i<2*n+10;i++) {
        ans = max(ans, ap[i]+bp[i]);
    }
    cout<<ans<<endl;
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