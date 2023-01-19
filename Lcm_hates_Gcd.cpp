/*
    author:Karan
    created:18.01.2023 20:23:36
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

ll count(ll a, ll b, ll c) {
    return (a*(c/__gcd(a, c))) - __gcd(b, c);
}
void solve() {
    //min val of A*x/gcd(A,x) - gcd(B, x);
    ll a, b;
    cin>>a>>b;
    ll p = __gcd(a, b);
    ll q = (a*b)/ __gcd(a, b);
    ll res = 1e18+7;
    
    cout<<min({count(a, b, p), count(a, b, q), count(a, b, a), count(a, b, b), count(a, b, 1)})<<endl;
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