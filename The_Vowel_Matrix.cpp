/*
    author:Karan
    created:14.06.2023 20:22:09
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


bool isVovel(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
        return true;
    } 
    return false;
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
ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<ll> pp;
    for(ll i = 0; i < n; i++) {
        if(isVovel(s[i])) {
            pp.push_back(i);
        }
    }
    ll res = 1;

    for(ll i=k-1; i < pp.size(); i += k) {
        if(i+1 < pp.size()) {

            res = mul(res, pp[i+1] - pp[i]);
        }
    }

    cout<<res<<endl;
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