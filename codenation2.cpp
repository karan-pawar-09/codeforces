/*
    author:Karan
    created:03.07.2022 13:41:15
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


const int mod = 1e9+7;
const int N = 1e5+10;
ll add(int a, int b) {
    return (a+b)%mod;
}
ll mul(int a, int b) {
    return ((a%mod)*(b%mod))%mod;
}
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
nCr AA(N,mod);

void solve() {
    int A,B;
    cin>>A>>B;
    vector<int> pat(A+10);
    pat[0]=1;
    int diff = B+(A/2);
    for(int i=1;i<A;i++) {
        pat[i]=add(add(pat[i-1],diff),i-1);
    }
    int start = (A/2)-B;
    int end = (A/2)+B;
    int sum=0;
    for(int i=start;i<=end;i++) {
        sum=add(sum,pat[i]);
    }
    for(int i=0;i<A;i++) {
        cout<<pat[i]<<" ";
    }
    cout<<endl;
    int x = (A/2)-B;
    cout<<AA.C((2*(A-1)),(A-1))-sum*AA.C(2*x,x)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}