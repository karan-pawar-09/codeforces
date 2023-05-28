/*
    author:Karan
    created:27.05.2023 18:51:27
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

vector<ll> res;

void dfs(ll node, ll par, vector<vector<ll>> & graph) {
    res.push_back(node);
    for(auto x: graph[node]) {
        if(x != par) {
            dfs(x, node, graph);
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n-1);
 
    vector<ll> con(n+1, 0);
    for(ll i=0;i<n-1;i++) {
        cin>>arr[i].first;
        cin>>arr[i].second;
        con[arr[i].first]++;
        con[arr[i].second]++;
    }
    if(n==3) {
        cout<<2<<endl;
        return;
    }
    vector<vector<ll>> graph(n+1);
    vector<ll> nextcon(n+1, 0);
    for(auto x: arr) {
        if(con[x.first] > 1 && con[x.second] > 1) {
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
            nextcon[x.first]++;
            nextcon[x.second]++;
        }
    }
    ll node = -1;
    for(ll i=1;i<=n;i++) {
        if(nextcon[i] == 1) {
            node = i;
        }
    }
    if(node == -1) {
        for(auto x: con) {
            if(x>1) {
                cout<<x<<endl;
                return;
            }
        }
    }
    dfs(node, -1, graph);
    vector<ll> answer;
    
    for(ll i=0;i<res.size();i++) {
        if(i%3==0) {
            answer.push_back(con[res[i]]);
        }
    }
    sort(all(answer));
    for(auto x: answer) cout<<x<<" ";
    cout<<endl;
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