/*
    author:Karan
    created:22.06.2023 11:29:05
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
map<pair<pair<int, int>, int>, int> M;

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
    return ((a % mod) * (b % mod)) % mod;
}
ll add(ll a, ll b) {
    return ((a % mod) + (b % mod)) % mod;
}

ll rec(vector<ll> &arr, ll n, ll l, ll r, vector<ll> &pref, string &s, ll ind) {
    if(ind >= n) {
        ll kp = pref[r-1];
        if(l - 1 >= 0) {
            kp -= pref[l - 1];
        } 
        return kp;
    }
    if(M.find({{l, r}, ind}) != M.end()) {
        return M[{{l, r}, ind}];
    }
    ll ans = 0;
    if(l + 1 == r) {
        ans = arr[l];
        return ans;
    }
    for(ll i = l; i < r-1; i++) {
        if(s[ind] == 'L') {
            ans = add(ans, rec(arr, n, l, i+1, pref, s, ind+1));
        } else {
            ans = add(ans, rec(arr, n, i+1, r, pref, s, ind+1));
        }
    }
    ans = mul(ans, modInv(r - l - 1, mod));
    M[{{l, r}, ind}] = ans;
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    M.clear();
    vector<ll> arr(n);
    vector<ll> pref(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(i == 0) {
            pref[i] = arr[i];
        } else {
            pref[i] = pref[i-1] + arr[i];
        }
    }
    string s;
    cin >> s;
    cout<<rec(arr, m, 0, n, pref, s, 0)<<endl;
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

