/*
    author:Karan
    created:18.06.2023 20:18:29
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

ll ct(ll k) {
    if(k%2) return k/2;
    else return (k/2) -1 ;
}
ll binarysearch(ll k, ll coins, ll n) {
    ll l = 0;
    ll r = n;
    while(l+1 < r) {
        ll m = l + (r-l)/2;
        if(m * k <= coins) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}
void solve() {
    ll n, k, g;
    cin >> n >> k >> g;
    ll coins = k * g;
    ll res = 0;
    ll ans = 0;
    ll req = binarysearch(ct(g), coins, n);
    ans += req * ct(g);
    coins -= req * ct(g);
    if(req < (n - 1)) {
        req = n - 1;
        ans += coins;
        coins = 0;
    }
    ll rem = coins;
    if(rem >= 0) {
        ll pp = rem % g;
        if(pp * 2 >= g) {
            ans -= (g - pp);
        } else {
            ans += pp;
        }
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