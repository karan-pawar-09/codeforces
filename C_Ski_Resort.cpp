/*
    author:Karan
    created:06.06.2023 20:34:40
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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin >> a[i];
    }
    ll count = 0 ;
    ll res = 0;
    for(ll i = 0; i < n;i++) {
        if(a[i] <= q) {
            count++;
        } else {
            if(count >= k) {
                ll p = count - k + 1;
                if(p%2) {
                    res += p*((p+1)/2);
                } else {
                    res += (p/2)*(p+1);
                }
            }
            count = 0;
        }
    }
    if(count >= k) {
        ll p = count - k + 1;
        if(p%2) {
            res += p*((p+1)/2);
        } else {
            res += (p/2)*(p+1);
        }
    }
    cout<<res<<endl;
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