/*
    author:Karan
    created:04.01.2022 18:21:36
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

const ll mod=9999889;

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

ll mul(ll a, ll b) {
    return ((a%mod)*(b%mod))%mod;
}
ll fact[9999890];

void solve() {
    ll a,n;
    cin>>a>>n; 
    if(n>=mod) {
        cout<<0<<endl;
    }  
    else 
        cout<<mul(power(a,n,mod),fact[n])<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    fact[1]=1;
    for(ll i=2;i<9999890;i++) {
        fact[i]=mul(fact[i-1],i);
    }
    cin>>t;
    while(t--) {
        solve();
    }
}