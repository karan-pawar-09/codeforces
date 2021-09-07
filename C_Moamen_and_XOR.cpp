/*
author:Karan
created:09.08.2021 21:07:50
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)1e9+7;
const ll mx=2e5+7;

ll fact[mx];
ll ifact[mx];

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

ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}


ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}

ll nCr(ll n,ll r) {
    return ((fact[n]%mod*ifact[n-r]%mod)%mod*ifact[r]%mod)%mod;
}

void solve1(ll n,ll k) {
    ll x=0LL;
    for(ll i=0;i<n;i+=2) {
        ll y=nCr(n,i);
        x=mod_add(x,y,mod);
    }
    vector<ll> dp(k+1,0);
    dp[0]=1LL;
    for(ll i=1;i<=k;i++) {
        dp[i]=dp[i-1]+(x%mod*dp[i-1]%mod)%mod;
        dp[i]%=mod;
    }

    cout<<dp[k]<<endl;
}

void solve2(ll n,ll k) {
    ll x=0LL;
    for(ll i=0;i<n;i+=2) {
        ll y=nCr(n,i);
        x=mod_add(x,y,mod);
    }
    vector<ll> dp(k+1,0);

    dp[0]=1LL;
    for(ll i=1;i<=k;i++) {
        ll y=power(2,(i-1)*n,mod);
        dp[i]=y+((x%mod)*(dp[i-1]%mod))%mod;
        dp[i]%=mod;
    }
    cout<<dp[k]<<endl;
 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    {
        fact[0]=1LL;
        ifact[0]=1LL;
        for(ll i=1;i<mx;i++) {
            fact[i]=i*fact[i-1];
            fact[i]%=mod;
            ifact[i]=modInv(fact[i],mod);
        }
    }
    ll t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;   
        if(n%2) {
            solve1(n,k);
        }
        else {
            solve2(n,k);
        }
    }
}



