/*
    author:Karan
    created:31.07.2022 18:11:54
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

const ll mod=(ll)998244353;
const ll N = 1e5;

set<ll> printDivisors(ll n) {
    set<ll> factors;
    for (ll i=1; i*i<= n; i++) {
        if (n%i == 0) {
            if (n/i == i)
                factors.insert(i);
            else {
                factors.insert(i); factors.insert(n/i);
            }
        }
    }
    return factors;
}

ll power(long long x, unsigned ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
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
nCr A(N,mod);

ll add(ll a, ll b) {
    return (a+b)%mod;
}
ll sub(ll a, ll b) {
    return (a-b+(mod*mod))%mod;
}
void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    map<ll,ll> freq;
    map<ll,ll> M;
    map<ll, map<ll,ll>> MM;
    for(ll i =0 ; i<n;i++) {
        cin>>arr[i];
        freq[arr[i]]++;
        set<ll> temp = printDivisors(arr[i]);
        for(auto x: temp) {
            M[x]++;
            MM[x][arr[i]]++;
        }
    }
    ll ans = 0;
    for(auto x: freq) {
        ans = sub(add(ans,power(2, x.second, mod)),1);
    }
    for(auto x: M) {
        if(x.second>=x.first) {
            ans = add(ans, A.C(x.second, x.first));
        }
    }
    for(auto x: MM) {
        for(auto y: x.second) {
            if(y.second>=x.first) {
                ans = sub(ans, A.C(y.second, x.first));
            }
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
    //cin>>t;
    while(t--) {
        solve();
    }
}