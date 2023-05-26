/*
    author:Karan
    created:26.03.2023 20:07:25
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
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
    }
    for(ll i=0;i<n-1;i++) {
        if((max(a[i], b[i]) > max(a[n-1], b[n-1])) || (min(a[i], b[i]) > min(a[n-1], b[n-1]))) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
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