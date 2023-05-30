/*
    author:Karan
    created:28.05.2023 20:26:46
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


const int mx = 2e5+10;
map<pair<int,int>, int> M;
vector<int> graph[mx];
int res;
void dfs(int node, int par, int ans, int rank) {
    res = max(ans, res);
    for(auto x: graph[node]) {
        if(x != par) {
            int temp = ans;
            int tempRank = M[{x, node}];
            if(tempRank < rank) {
                temp++;
            }
            dfs(x, node, temp, tempRank);
        }
    }
}
void solve() {
    ll n;
    cin>>n;
    M.clear();
    res = -1;
    for(int i=0;i<=n;i++) {
        graph[i].clear();
    }
    vector<pair<int, int>> arr;
    for(ll i=0;i<n-1;i++) {
        ll a, b;
        cin>>a>>b;
        arr.push_back({a, b});
        graph[a].push_back(b);
        graph[b].push_back(a);
        M[{a, b}] = i;
        M[{b, a}] = i;
    }
   
    dfs(1, -1, 0, 100000000);
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