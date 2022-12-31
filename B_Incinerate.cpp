/*
    author:Karan
    created:30.12.2022 17:55:03
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
    ll n, k;
    cin >> n >> k;
    vector<ll> h(n), p(n);
    multiset<ll> ms;
    for(ll i = 0; i < n; i++) {
        cin >> h[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> p[i];
        ms.insert(p[i]);
    }
    vector<pair<ll, ll>> arr(n);
    for(ll i = 0; i < n; i++) {
        arr[i].first = h[i];
        arr[i].second = p[i];
    }
    sort(all(arr));
    ll i = 0;
    ll damage = 0;
    while(k>0 && i < n) {
        damage += k;
        while(i<n &&damage >= arr[i].first) {
            ms.erase(ms.find(arr[i].second));
            i++;
        }
        if(ms.size()) {
            k -= *ms.begin();
        }
    }
    if(i>=n) {
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