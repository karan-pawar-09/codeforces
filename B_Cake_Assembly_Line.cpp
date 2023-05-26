/*
    author:Karan
    created:05.02.2023 18:31:03
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
    ll n, w, h;
    cin >> n >> w >> h;
    vector<ll> a(n), b(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    } 
    for(ll i=0;i<n;i++) {
        cin>>b[i];
    }
    bool ans = true;
    ll canshift = 2*w - 2 * h;
    ll k = b[0]-h - a[0] + w;
    ll p = b[0]+h -a[0]-w;
    for(ll i=1;i<n;i++) {
        if(b[i]-h < p+a[i]-w) {
            ans = false;
        }
        if(b[i]+h > k+a[i]+w) {
            ans = false;
        }
        k = min(k, b[i]-h-a[i]+w);
        p = max(p, b[i]+h-a[i]-w);
    }
    if(ans) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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