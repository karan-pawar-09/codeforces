/*
    author:Karan
    created:13.11.2021 09:31:28
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

const ll N=1e6+10;
const ll mod=1e9+7;

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
ll add(ll a,ll b) {
    return (a+b)%mod;
}
ll mul(ll a,ll b) {
    return ((a%mod)*(b%mod))%mod;
}
void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll spt=0;
    for(auto x:s) {
        if(x=='0' || x=='9') {
            spt++;
        }
    }
    ll ans=0;
    for(ll i=1;i<=k;i++) {
        for(ll j=0;j<=spt and j<=i;j++) {
            ll sel1=A.C(spt,j);
            ll sel2=1;
            sel2=A.C(n-spt,i-j);
            if(i>j) {
                sel2=mul(sel2,(i-j)*2);
            }
            ans=add(ans,(sel1*sel2)%mod);
        }
    }
    cout<<ans<<endl;
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