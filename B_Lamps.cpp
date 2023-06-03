/*
    author:Karan
    created:03.06.2023 20:34:59
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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    vector<vector<ll>> graph(n+1);
    for(ll i=0;i<n;i++) {
        cin>>arr[i].first>>arr[i].second;
        graph[arr[i].first].push_back(arr[i].second);
    }
    for(auto &x: graph) {
        sort(all(x), greater<ll>());
    }
    for(auto &x: graph) {
        for(ll i=1;i<x.size();i++) {
            x[i] += x[i-1];
        }
    }
    ll ans = 0;
    for(ll i=1;i<=n;i++) {
        // cout<<i<<": ";
        // for(auto x: graph[i]) cout<<x<<" ";
        // cout<<endl;
        if(graph[i].size()) {
            ll maxi = min(i, (ll)graph[i].size());
            ans += graph[i][maxi-1];
        }
    }
    cout<<ans<<endl;

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