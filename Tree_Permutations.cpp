#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
long long int mod = 1e9 + 7;
 
void solve() {
    int n, ch;
    cin >> n >> ch; 
    int i, j, k, l; 
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int>> edge(n + 1); 
    for (i = 0; i < n - 1; i++) {
        cin >> j >> k;
        edge[j].push_back(k);
        edge[k].push_back(j);
    }
 
    for (i = 1; i <= n; i++)
        cin >> a[i];
 
    for (i = 1; i <= n; i++)
        cin >> b[i];
 
    vector<int> depth(n + 1, -1);
    vector<int> par(n + 1, -1);
    function<void(int, int, int)> dfs; 
    dfs = [&](int v, int value, int p) {
        par[v] = p;
        depth[v] = value;
 
        for (auto it : edge[v])
        {
            if (it == p)
                continue;
 
            dfs(it, value + 1, v);
        }
    }; 
    dfs(1, 0, -1); 
    vector<pair<int, int>> node; 
    for (i = 1; i <= n; i++)
        node.push_back({depth[i], i});
 
    sort(node.begin(), node.end()); 
    queue<int> dq; 
    for (i = node.size() - 1; i >= 0; i--)
        dq.push(node[i].second);
 
    int mis_mat = 0; 
    unordered_map<int, int> fre_mp; 
    function<void(int,int)> upd;
    upd = [&](int x, int element) {
        if (element == 1) {
            if (fre_mp[x] == 0)
                mis_mat++;
 
            fre_mp[x]++;
 
            if (fre_mp[x] == 0)
                mis_mat--;
 
        }
        else {
            if (fre_mp[x] == 0)
                mis_mat++;
 
            fre_mp[x]--;
 
            if (fre_mp[x] == 0)
                mis_mat--; 
        }
    }; 
    vector<int> visited(n + 1, 0); 
    vector<int> basee_vertex(n + 1); 
    while (dq.size() > 0) { 
        int element = dq.front();
        dq.pop(); 
        if (visited[element] == 1)
            continue;
 
        visited[element] = 1;
        int base_element = element;
        basee_vertex[element] = base_element; 
        upd(a[element], 1);
        upd(b[element], -1);
 
        while (mis_mat)        {
            element = par[element]; 
            if (element == -1 || visited[element]) {
                cout << "0" << endl;
                return;
            } 
            basee_vertex[element] = base_element; 
            visited[element] = 1;
            upd(a[element], 1);
            upd(b[element], -1);
        }
    } 
    if (ch == 1) {
        cout << "1" << endl;
        return;
    } 
    long long int ans = 1; 
    for (i = 1; i <= n; i++) {
        int valid_child = 0;
        if (basee_vertex[i] == i) {
            for (auto it : edge[i]) {
                if (par[it] == i)
                    valid_child++;
            }
        }
        ans *= (long long int)(valid_child + 1);
        ans %= mod;
    }
 
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 
    while (t--)
        solve();
}