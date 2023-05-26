/*
    author:Karan
    created:25.01.2023 20:22:36
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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    ll sum = 0;
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
        sum += arr[i];
    }
    ll cur = 0;
    ll maxgcd = 1;
    for(ll i=0;i<n;i++) {
        cur += arr[i];
        ll temp = sum - cur;
        if(i != n-1) {
            maxgcd = max(maxgcd, __gcd(cur, temp));
        }
    }
    cout<<maxgcd<<endl;
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