/*
    author:Karan
    created:26.07.2022 22:42:36
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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n+1);
    ll total = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> arr[i];
        total += arr[i];
    }
    vector<pair<ll, ll>> pairs(m);
    vector<vector<ll>> graph(n+1);

    set<ll> s;
    ll sum = 0;
    for(ll i = 0; i < m; i++) {
        cin >> pairs[i].first >> pairs[i].second;
        graph[pairs[i].first].push_back(pairs[i].second);
        graph[pairs[i].second].push_back(pairs[i].first);
        s.insert(pairs[i].first);
        s.insert(pairs[i].second);
    }
    for(auto x: s) {
        sum+=arr[x];
    }
  
    if(m%2) {
        ll ans = 1e18+7;
        for(ll i = 1; i <= n; i++) {
            if(graph[i].size()%2) {
                ans = min(ans, arr[i]);
            }
        }
        for(ll i = 0; i < m; i++) {
            if((graph[pairs[i].first].size() + graph[pairs[i].second].size() - 1) % 2) {
                ans = min(ans, arr[pairs[i].first]+arr[pairs[i].second]);
            }
        }
        cout<<ans<<endl;
    } else {
        cout<< 0 << endl;
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
