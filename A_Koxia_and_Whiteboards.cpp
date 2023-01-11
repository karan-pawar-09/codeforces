/*
    author:Karan
    created:01.01.2023 10:41:14
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    multiset<ll> ms;
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        ms.insert(a[i]);
    }
    for(ll j=0;j<m;j++) {
        cin>>b[j];
    }
    for(ll i=0;i<m;i++) {
        {
            ms.erase(ms.begin());
            ms.insert(b[i]);
        }
    }
    ll ans = 0;
    for(auto x: ms) {
        ans += x;
    }
    cout << ans << endl;
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