// /*
//     author:Karan
//     created:24.12.2022 23:32:15
// */
// #if true
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define all(ar) ar.begin(),ar.end()
// #define endl '\n'
// #define mset(a,x) memset(a,x,sizeof(a))
// #endif

// const ll mx = 1e5+10;
// const ll inf = 1e18+10;

// vector<pair<ll, ll>> arr[mx];
// vector<pair<ll, ll>> ar[mx];
// ll d[mx], d1[mx];

// ll ans, n;

// ll ceil(ll a, ll b) {
//     return (a+b-1)/b;
// }

// void dijkstra(ll s, bool k) {
//     if(k) {
//         d[s] = 0;
//     } else {
//         d1[s] = 0;
//     }
//     set<pair<ll, ll>> q;
//     q.insert({0, s});
//     while (!q.empty()) {
//         ll v = q.begin()->second;
//         q.erase(q.begin());
//         if(k) {
//             for (auto edge : arr[v]) {
//                 ll to = edge.first;
//                 ll len = edge.second;
                
//                 if (d[v] + len < d[to]) {
//                     q.erase({d[to], to});
//                     d[to] = d[v]+len;
//                     q.insert({d[to], to});  
//                 } 
                
//             }
//         } else {
//             for (auto edge : ar[v]) {
//                 ll to = edge.first;
//                 ll len = edge.second;
                
//                 if (d1[v] + len < d1[to]) {
//                     q.erase({d1[to], to});
//                     d1[to] = d1[v]+len;
//                     q.insert({d1[to], to});  
//                 } 
                
//             }
//         }
//     }
// }


// void solve() {
//     ll m, a, b, c;
//     cin >> n >> m;
//     ans = inf;
//     vector<pair<pair<ll, ll>, ll>> array;
//     for(ll i = 0; i <= n; i++) {
//         d[i] = inf;
//         d1[i] = inf;
//     }
//     for(ll i = 0; i < m; i++) {
//         cin >> a >> b >> c;
//         array.push_back({{a, b}, c});
//         ar[b].push_back({a, c});
//         arr[a].push_back({b, c});
//     }
//     dijkstra(1, true);
//     dijkstra(n, false);
//     ll ans = inf;
//     for(auto x: array) {
//         ll temp = d[x.first.first] + x.second/2 + d1[x.first.second];
//         ans = min(ans, temp);
//     }
//     cout<<ans<<endl;
// }

// int32_t main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ll t=1;
//     //cin>>t;
//     while(t--) {
//         solve();
//     }
// }

/*
    author:Karan
    created:27.12.2022 15:15:40
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
    int n, m;
    cin >> n >> m;
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}