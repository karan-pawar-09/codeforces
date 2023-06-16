/*
    author:Karan
    created:09.06.2023 21:04:20
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

const ll mod = 1e9+7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll res = 1;
    int count = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] % 2) {

        } else {
            count++;
            res *= 2;
        }
        res %= mod;
    }

    res %= mod;
    
    if(count == n) {
        res -= 1;
        res += mod;
        res %= mod;
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