/*
    author:Karan
    created:22.11.2021 22:26:47
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

const ll mod=(ll)1e9+7;

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
ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}
ll add(ll a,ll b) {
    return (a+b)%mod;
}
ll mul(ll a,ll b) {
    return (a*b)%mod;
}
ll sub(ll a,ll b) {
    return (a-b+mod)%mod;
}
void solve() {
    ll n;
    cin>>n;
    ll sum=mul(n,mul(add(n,1),modInv(2,mod)));
    sum=mul(sum,sum);
    ll k=mul(modInv(6,mod),mul(n,mul((n+1)%mod,(mul(2,n)+1)%mod)));
    ll ans=sub(sum,k);
    cout<<mul(ans,modInv(n,mod))<<endl;
  
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