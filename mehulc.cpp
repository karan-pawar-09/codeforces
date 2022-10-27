/*
    author:Karan
    created:15.10.2022 17:29:32
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
const ll N = 1e5+10;
struct nCr{
    ll mxN, M; 
    vector<ll> fact, ifact; 
    inline ll mul(ll a, ll b) { return a *1LL* b % M ;}
    ll power(ll a, ll n) {
        if(n == 0) return 1 ; 
        ll p = power(a, n/2) % M ; 
        p = mul(p, p) ;  
        return n & 1 ? mul(p, a) : p ; 
    }
    ll invMod(ll a) {return power(a,M-2);}
    void pre() {
        fact[0] = 1 ;
        for(ll i = 1;i< mxN;++i) fact[i] = mul(i, fact[i-1]) ;
        ifact[mxN-1] = invMod(fact[mxN-1]) ; 
        for(ll i = mxN-1 ; i>0 ;--i) ifact[i-1] = mul(ifact[i], i) ;
    }
    nCr(ll _mxN, ll _M) {
        mxN = _mxN + 1; 
        M = _M ; 
        fact.resize(mxN) ; 
        ifact.resize(mxN) ;
        pre() ;  
    }
    ll C(ll n, ll r) {
        if (n < r || r < 0 || n < 0) return 0;
        return mul(fact[n], mul(ifact[r], ifact[n-r])) ;
    }
    ll factorial(ll a) {
        return fact[a];
    }
};
nCr A(N,mod);

void solve() {
    ll n, p, c;
    cin>>n>>p>>c;
    cout<< A.C(n, p+c)<<endl;
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