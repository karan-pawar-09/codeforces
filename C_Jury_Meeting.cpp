/*
    author:Karan
    created:08.09.2021 20:35:36
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=998244353;
const ll N = 2e5 +5 ; 
 
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

ll mul(ll a, ll b) {
    return (a*b)%mod;
}
ll sub(ll a, ll b) {
    return (a-b+mod)%mod;
}
ll add(ll a, ll b) {
    return (a+b)%mod;
}


void solve() {
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(all(arr));
    if(arr[n-1]-arr[n-2]>1) {
        cout<<0<<endl;
    }
    else if(arr[n-1]==arr[n-2]) {
        cout<<A.factorial(n)<<endl;
    }
    
    else {
        ll c1=0;
        ll c2=0;
        for(int i=0;i<n;i++) {
            if(arr[i]==arr[n-1]) {
                c1++;
            }
            if(arr[i]==arr[n-2]) {
                c2++;
            }
        }
        ll others=n-c1-c2;
        ll ans=A.factorial(n);
        for(ll i=0;i<n;i++) {
            ll after = n - i - 1;
            ll cur = mul(A.C(others, after), A.factorial(after));
            cur = mul(cur, A.factorial(i));
            ans = sub(ans, cur);
        }
        cout<<ans<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}