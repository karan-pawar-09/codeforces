/*
    author:Karan
    created:01.07.2023 17:46:00
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

const vector<ll> i_move = {1, -1, 0, 0};
const vector<ll> j_move = {0, 0, 1, -1};
bool isGood(ll i, ll j, vector<string> &graph, set<char> &st, vector<vector<bool>> & visited) {
    ll n = graph.size();
    ll m = graph[0].size();
    if(i >= n || i < 0) return false;
    if(j >= m || j < 0) return false;
    if(visited[i][j]) return false;
    if(!st.count(graph[i][j])) return false;
    return true;
}
bool bfs(vector<string> & graph, map<char, char> &prev, set<char> &st) {
    queue<pair<ll, ll>> q;
    ll n = graph.size();
    ll m = graph[0].size();
    vector<vector<bool>> visited(graph.size(), vector<bool> (graph[0].size(), false));
    if(graph[0][0] == 's') {
        q.push({0, 0});
        visited[0][0] = true;
    }
    while(q.size()) {
        pair<ll, ll> cor = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++) {
            ll newi = cor.first + i_move[i];
            ll newj = cor.second + j_move[i];
            if(isGood(newi, newj, graph, st, visited)) {
                if(prev[graph[newi][newj]] == graph[cor.first][cor.second]) {
                    visited[newi][newj] = true;
                    q.push({newi, newj});
                }
            }
        }
    }   
    return visited[n-1][m-1];
}
void solve() {
    ll h, w;
    cin >> h >> w;
    vector<string> graph(h);
    for(ll i = 0; i < h; i++) {
        cin >> graph[i];
    }
    vector<vector<bool>> dp(h, vector<bool> (w, false));
    if(graph[0][0] == 's') dp[0][0] = true;
    map<char, char> prev;
    prev['s'] = 'e';
    prev['n'] = 's';
    prev['u'] = 'n';
    prev['k'] = 'u';
    prev['e'] = 'k';
    set<char> st;
    for(auto x: prev){
        st.insert(x.first);
    }
    bfs(graph, prev, st)?cout<<"Yes"<<endl:cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}