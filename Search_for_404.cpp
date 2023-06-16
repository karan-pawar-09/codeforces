/*
    author:Karan
    created:14.06.2023 20:33:48
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

const ll mod = 1e9+7;
ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
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
    cin >> n;
    string s;
    cin >> s;
    vector<ll> dp4(n, 0);
    vector<ll> dp40(n, 0);
    vector<ll> dp404(n, 0);
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(i == 0) {
            if(s[i] == '4') {
                dp4[0] = 1;
            } else if(s[i] == '0') {

            } else {
                dp4[0] = 1;
                ct++;
            }
        } else {
            if(s[i] =='4') {
                dp4[i] = dp4[i-1];
                dp40[i] = dp40[i-1];
                dp404[i] = dp404[i-1];
                dp4[i] = add(dp4[i],  power(2, ct, mod));
                dp404[i] = add(dp404[i],  dp40[i-1]);
            } else if(s[i]=='0') {
                dp4[i] = dp4[i-1];
                dp40[i] = dp40[i-1];
                dp404[i] = dp404[i-1];
                dp40[i] = add(dp40[i], dp4[i-1]);
            } else {
                dp4[i] = mul(2, dp4[i-1]);
                dp40[i] = mul(2, dp40[i-1]);
                dp404[i] =mul(2, dp404[i-1]);
                dp4[i] = add(dp4[i],  power(2, ct, mod));
                dp404[i] = add(dp404[i], dp40[i-1]);
                dp40[i] = add(dp40[i], dp4[i-1]);
                ct++;
            }
        }
    }
    cout<<dp404[n-1]<<endl;
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