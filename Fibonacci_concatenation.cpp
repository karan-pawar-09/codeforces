/*
author:Karan
created:17.08.2021 22:17:20
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mx=1e5+7;
const ll mod=1e9+7;

ll ones[mx];
ll size[mx];

ll add(ll a,ll b,ll mod) {
    return (a+b)%mod;
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

void solve() {
    ll n;
    cin>>n;
    ll ans=(ones[n]%mod*power(2,((size[n]-1)+mod-1)%(mod-1),mod)%mod)%mod;
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    ones[0]=0;
    ones[1]=1;
    for(ll i=2;i<mx;i++) {
        ones[i]=add(ones[i-1],ones[i-2],mod);
    }
    size[0]=1;
    size[1]=1;
    for(ll i=2;i<mx;i++) {
        size[i]=add(size[i-1],size[i-2],mod-1);
    }
    while(t--) {
        solve();
    }
}