/*
    author:Karan
    created:20.06.2023 20:26:57
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
vector<ll> arr[mx];
ll cnt[mx];

void dfs(ll node, ll par) {
    ll res = 0;
    ll branches = 0;

    for(auto x: arr[node]) {
        if(x != par) {
            branches++;
            dfs(x, node);
            res += cnt[x];
        }
    }
    
    if(branches == 0) cnt[node] = 1;
    else cnt[node] = res;
}

void solve() {
    ll n;
    cin >> n;
    for(ll i = 0; i <=n; i++) {
        arr[i].clear();
        cnt[i] = 0;
    }
    for(ll i = 0; i < n-1; i++) {
        ll u, v;
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    dfs(1, 0);
    ll q;
    cin >> q;
    while(q--) {
        ll a, b;
        cin >> a >> b;
        cout<<cnt[a] * cnt[b]<<endl;
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