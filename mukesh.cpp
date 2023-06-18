/*
    author:Karan
    created:17.06.2023 21:18:06
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

const int mx = 1e5 + 10;
vector<int> graph[mx];
int F[mx];
bool visited[mx];
map<pair<int, int>, int> M;

int dfs(int node, int cap) {
    int res = F[node];
    visited[node] = true;
    for(auto x: graph[node]) {
        if(!visited[x]) {
            int xxx = M[{x, node}];
            if(M[{x, node}] <= cap) {
                res += dfs(x, cap);
            }
        }
    }
    return res;
}

bool isGood(int m, int X) {
    for(int i = 0; i < mx; i++) visited[i] = false;
    int res = dfs(0, m);
    if(res >= X) return true;
    else return false;
}

int binarysearch(int X) {
    int l = -1;
    int r = 1e9+10;
    while(l + 1 < r) {
        int m = l + (r - l) / 2;
        if(isGood(m, X)) {
            r = m;
        } else {
            l = m;
        }
    }
    if(isGood(r, X)) return r;
    else return -1;
}

int fightingTraffic(int n, int m, vector<vector<int>> &roads, vector<int> &t, vector<int> & f, int x) {
    M.clear();
    for(int i = 0; i <= n; i++) {
        graph[i].clear();
    }
     for(int i = 0; i < m; i++) {
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    for(int i = 0; i < m; i++) {
        M[{roads[i][0], roads[i][1]}] = t[i];
        M[{roads[i][1], roads[i][0]}] = t[i];
    }
    for(int i = 0; i < n; i++) {
        F[i] = f[i];
    } 
    return binarysearch(x);
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> roads(m, vector<int> (2));
    vector<int> T(m);
    for(int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }
    for(int i = 0; i < m; i++) {
        cin >> T[i];
    }
    vector<int> f(n);
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }
    cout<<fightingTraffic(n, m, roads, T, f, x)<<endl;
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