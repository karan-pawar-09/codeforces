/*
    author:Karan
    created:20.02.2023 23:39:59
*/
#if true
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
#define mset(a,x) memset(a,x,sizeof(a))
#endif

bool check(vector<ll> &a, vector<ll> &b, ll m , ll k) {
    ll temp = 0;
    for(ll i=0;temp <= k && i<a.size();i++) {
        if((m*a[i]) >= b[i]) {
            temp += (m*a[i]) - b[i];
        }
    }
    return (temp <= k);
}

ll binarysearch(vector<ll> &a, vector<ll> &b, ll k) {
    ll l = 0;
    ll r = 2e9+10;
    while(l+1 < r) {
        ll m = l + (r-l)/2;
        if(check(a, b, m, k)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i= 0; i < n; i++) {
        cin >> b[i];
    }
    cout<<binarysearch(a, b, k)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}