/*
    author:Karan
    created:19.03.2022 20:23:20
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
vector<int> arr[mx];
bool visited[mx];
queue<int> qu;

void bfs() {
    vector<int> ar;
    while (qu.size()) {
        int node = qu.front();
        qu.pop();
        for (auto x : arr[node]) {
            if (!visited[x]) {
                visited[x] = true;
                ar.push_back(x);
            }
        }
    }
    for (auto x : ar) {
        qu.push(x);
    }
}
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    while (qu.size()) {
        qu.pop();
    }
    for (int i = 0;i <= n;i++) {
        arr[i].clear();
        visited[i] = false;
    }
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int node;
            cin >> node;
            if (!visited[node]) {
                visited[node] = true;
                qu.push(node);
            }
        }
        else if (type == 2) {
            int t;
            cin >> t;
            while (t--) {
                if (!qu.size()) break;
                bfs();
            }
        }
        else {
            int p;
            cin >> p;
            visited[p] ? cout << "YES" << endl : cout << "NO" << endl;
        }
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
}