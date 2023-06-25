/*
    author:Karan
    created:21.06.2023 20:15:33
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
    ll n, m, h;
    cin >> n >> m >> h;
    vector<ll> a(n), b(m);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> b[i];
        b[i] *= h;
    }

    sort(all(b));
    sort(all(a));
    ll res = 0;
    for(ll i = n-1, j = m -1; i >= 0 && j >=0; i--, j--) {
        res += min(b[j], a[i]);
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