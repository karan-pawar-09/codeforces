/*
    author:Karan
    created:08.01.2022 17:30:35
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

ll f(ll i) {
    return (i*i)+(2*i)+3;
}
void solve() {
    ll t;
    cin>>t;
    ll k=f(t)+t;
    k=f(k);
    ll p=f(t);
    p=f(p);
    p=f(p+k);
    cout<<p<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}