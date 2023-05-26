/*
    author:Karan
    created:03.02.2023 11:25:07
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

ll mul(ll a, ll b) {
    return ((a%mod)*(b%mod)%mod);
}
ll mul(ll a, ll b, ll c) {
    return ((a%mod) * mul(b, c))%mod;
}
ll add(ll a, ll b) {
    return (a+b)%mod;
}
ll add(ll a, ll b, ll c) {
    return (a+add(b, c))%mod;
}
ll sqr(ll a) {
    return mul(a, a);
}

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> s(n+1);
    vector<pair<ll, ll>> sq(n+1);
    s[0] = {0, 0};
    sq[0] = {0, 0};
    for(ll i=1;i<=n;i++) {
        ll prev = mul(modInv(2, mod), add(s[i-1].first, s[i-1].second));
        ll one = mul(modInv(2, mod), sqr(prev+modInv(power(p, i-1, mod), mod)));
        ll two = mul(modInv(2, mod), sqr(prev));
        one = add(one, two);
        one = mul(modInv(2, mod), one);
        s[i].first = mul(modInv(2, mod), add(prev, modInv(power(p, i-1, mod), mod)));
        s[i].second = mul(modInv(2, mod), prev);
        cout<<add(one, sqr(prev))<<" ";
    }
    cout<<endl;
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