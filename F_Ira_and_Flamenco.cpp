/*
    author:Karan
    created:19.06.2023 22:57:00
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

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
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

ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    ll prev = arr[0];
    ll count = 1;
    map<ll, ll> dp;
    for(ll i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
            count++;
        } else {
            dp[prev] = count;
            count = 1;
        }
        prev = arr[i];
    }
    dp[prev] = count;
    prev = 1;
    vector<ll> ar;
    for(auto &x: dp) {
        ar.push_back(x.first);
        x.second = mul(x.second, prev);
        prev = x.second;
    }
    ll res = 0;
    for(ll i = 0; i < ar.size(); i++) {
        if(i + m - 1 < ar.size() && (ar[i + m - 1] == ar[i] + m - 1)) {
            ll ttt = dp[ar[i + m - 1]];
            if(i > 0) {
                ttt = mul(ttt, modInv(dp[ar[i-1]], mod));
            }
            res = add(res, ttt);
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