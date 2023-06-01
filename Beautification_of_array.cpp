/*
    author:Karan
    created:01.06.2023 10:22:34
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

bool check(vector<ll> &arr, ll k, ll res) {
    ll req = 0;
    for(auto x: arr) {
        if(x >= res) {

        } else {
            req += (res - x);
        }
    }
    return (req <= k);
} 

ll binarysearch(vector<ll> &arr, ll k) {
    ll l = arr[0];
    ll r = (1e11) + 1;
    while(l+1 < r) {
        ll m = l+(r-l)/2;
        if(check(arr, k, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
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
ll add(ll a, ll b) {
    return ((a % mod) + (b % mod))%mod;
}
ll sub(ll a, ll b) {
    ll k = (a %mod) - (b%mod);
    while(k < 0) {
        k += mod;
    }
    return (k) % mod;
}
ll modInv(ll a,ll mod) {
    return power(a,mod-2,mod) % mod ;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(all(arr));
    ll maxi = binarysearch(arr, k);
    for(ll i = 0; i < n; i++) {
        if(arr[i] >= maxi) {

        } else {
            k -= (maxi - arr[i]); 
            arr[i] = maxi;
        }
    }

    sort(all(arr));

    for(ll i=0;i<k;i++) {
        arr[i]++;
    }

    ll sum = 0;
    for(auto x: arr) {
        sum = add(sum, x%mod);
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans = add(ans, mul(arr[i], sub(sum, arr[i])));
    }
    cout << mul(ans, modInv(2, mod)) << endl;
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