/*
    author:Karan
    created:18.06.2023 13:35:28
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

ll ceil(ll a, ll b) {
    return (a+b-1)/b;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll pos = 0;
    ll neg = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > 0) pos++;
        else neg++;
    }
    if(pos >= neg) {
        if(neg % 2) {
            cout<<1<<endl;
            return;
        } else {
            cout<<0<<endl;
        }
    } else {
        ll min = ceil(n, 2);
        ll res = min - pos;
        if((n - min) % 2) {
            cout<<res + 1<<endl;
        } else {
            cout<<res<<endl;
        }
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