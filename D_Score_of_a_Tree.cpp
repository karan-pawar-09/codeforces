/*
    author:Karan
    created:23.01.2023 08:49:14
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

const ll mx = 2e5+10;
vector<ll> graph[mx];
const ll mod = 1e9+7;

pair<ll, ll> dfs(ll node, ll par) {
    ll ht = 0;
    ll sum = 0;
    for(auto x: graph[node]) {
        if(x != par) {
            pair<ll, ll> temp = dfs(x, node);
            ht = max(ht, temp.second);
            sum += temp.first;
        }
    }
    ht++;
    return {ht+sum, ht};
}

ll mul(ll a, ll b) {
    return ((a%mod) * (b%mod))%mod;
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
    for(ll i = 0; i <= n; i++) {
        graph[i].clear();
    }
    for(ll i=0;i<n-1;i++) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<mul(power(2, n-1, mod), dfs(1, 0).first)<<endl;
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