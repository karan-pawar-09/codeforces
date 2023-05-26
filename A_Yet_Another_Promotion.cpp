/*
    author:Karan
    created:12.02.2023 14:06:18
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

ll binarysearch(ll n, ll mm) {
    ll l = 0;
    ll r = 1e9+10;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if((mm*m + m) <= n) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
ll calc(ll k, ll a, ll b, ll n, ll m) {
    k = min(k, n);
    ll ans = (m*k)*a;
    if(n-(k*(m+1)) >= 0) {
        ans += (n-(k*(m+1))) * min(b, a);
    }
    return ans;
}

void solve() {
    ll a, b;
    cin>>a>>b;
    ll n, m;
    cin>>n>>m;
    ll k = binarysearch(n, m);
    cout<<min({calc(k, a, b, n, m), calc(k+1, a, b, n, m)})<<endl;
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