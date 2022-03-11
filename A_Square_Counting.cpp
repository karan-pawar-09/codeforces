/*
    author:Karan
    created:04.03.2022 21:14:23
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
    ll n,s;
    cin>>n>>s;
    ll l=-1;
    ll r=n+1;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if((m*(n*n)+(n+1-m)*(n-1))>=s) {
            r=m;
        } else {
            l=m;
        }
    }
    cout<<r<<endl;
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