/*
    author:Karan
    created:18.06.2023 20:05:18
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
    cin >> n;
    vector<ll> arr(n);
    vector<ll> P(1000, 0);
    ll mx = 0;
    for(ll i = 0; i < n;i++) {
        cin>>arr[i];
        P[arr[i]]++;
        mx = max(mx, arr[i]);
    }
    for(ll i = 1; i <= mx; i++) {
        if(P[i] > P[i-1]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    
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