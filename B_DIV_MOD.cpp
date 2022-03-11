/*
    author:Karan
    created:08.03.2022 20:12:03
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

ll fun(ll p, ll a) {
    ll cur=(p/a)+(p%a);
    return cur;
}
void solve() {
    ll l,r,a;
    cin>>l>>r>>a;
    ll k=r/a;
    ll pt=a*k;
    pt--;
    ll val=fun(l,a);
    val=max(val,fun(r,a));
    if(pt>=l)
        val=max(val,fun(pt,a));    

    cout<<val<<endl;
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