/*
    author:Karan
    created:17.06.2023 18:05:55
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
    vector<ll> arr(n+1);
    multiset<ll> ms;
    multiset<ll, greater<ll>> extra;
    for(ll i = 0; i < k; i++) ms.insert(0);
    for(ll i = k; i < n; i++) extra.insert(0);
    ll res = 0;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        ll rem = arr[a];
        arr[a] = b;
        if(ms.find(rem) != ms.end()) {
            ms.erase(ms.find(rem));
            res -= rem;
        } else {
            extra.erase(extra.find(rem));
        }
        extra.insert(b);
        while(ms.size() < k) {
            res += *extra.begin();
            ms.insert(*extra.begin());
            extra.erase(extra.begin());
        }
        while(*ms.begin() < *extra.begin()) {
            ll temp = *ms.begin();
            ll temp1 = *extra.begin();
            res -= temp;
            res += temp1;
            ms.erase(ms.begin());
            extra.erase(extra.begin());
            ms.insert(temp1);
            extra.insert(temp);
        }
        cout<<res<<endl;
    }

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