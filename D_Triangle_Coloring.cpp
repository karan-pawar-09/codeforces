/*
    author:Karan
    created:19.02.2023 03:54:43
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

const ll MOD = 998244353;

ll add(ll x, ll y)
{
    return ((x + y) % MOD + MOD) % MOD;
}

ll mul(ll x, ll y)
{
    return x * 1ll * y % MOD;   
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, MOD - 2);    
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 1;
    for(ll i=0;i<n/3;i++) {
        ll a, b, c;
        cin >> a>>b>>c;
        ll suma = a+b;
        ll sumb = b+c;
        ll sumc = a+c;
        ll maxi = max({suma, sumb, sumc});
        ll count = 0;
        if(suma == maxi) count++;
        if(sumb == maxi) count++;
        if(sumc == maxi) count++;
        ans *= (count);
        ans %= MOD;
    }
    for(ll i = 1; i <= n / 6; i++)
        ans = mul(ans, divide(i + n / 6, i));

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