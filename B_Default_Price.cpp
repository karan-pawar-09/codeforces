/*
    author:Karan
    created:01.07.2023 17:34:58
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
    vector<string> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<string> ar(m);
    for(ll i = 0; i < m; i++) {
        cin >> ar[i];
    }
    vector<ll> p(m+1);
    for(ll i = 0; i <= m; i++) {
        cin >> p[i];
    }
    map<string, ll> M;
    for(ll i = 0; i < m; i++) {
        M[ar[i]] = p[i+1];
    }
    ll res = 0;
    for(auto x: arr) {
        if(M.find(x) != M.end()) {
            res += M[x];
        } else {
            res += p[0];
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
    //cin>>t;
    while(t--) {
        solve();
    }
}