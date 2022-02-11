/*
    author:Karan
    created:02.02.2022 21:13:19
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

ll xx;
ll printDivisors(ll n) {
    // Vector to store half of the divisors
    vector<ll> v;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (n / i == i) {

            }         
            else {
                v.push_back(n / i);
            }
        }
    }
    ll res=0;
    for (ll i = v.size() - 1; i >= 0; i--) {
        xx+=modInv(v[i],mod);
        res+=v[i];
    }
        
    return res;
}
 
void solve() {
    ll x,a,b;
    cin>>x>>a>>b;
    xx=0;
    ll n=(x*b)/a;
    ll pp=(a*modInv(b,mod))%mod;
    if(x>=n) {
        if((x*b)%a==0) {
            cout<<n<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    } else {
        cout<<-1<<endl;
    }
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