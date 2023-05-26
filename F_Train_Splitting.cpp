#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#define sz(x) ((int)x.size())
const char nl = '\n';

template<class t, class u> bool pmin(t &a, u b) {if (b < a) {a = b; return true;} else return false;}
template<class t, class u> bool pmax(t &a, u b) {if (a < b) {a = b; return true;} else return false;}

const int N = 100;
vector<pair<int, int> > g[N];

void solve(int n, vector<pair<int, int>> & temp) {
    vector<int> ans(temp.size(), -1);
    int count = 1;
    for(int i=0;i<temp.size();i++) {
        if(temp[i].first - temp[i].second == 1 || temp[i].first - temp[i].second == (n-1)) {
            ans[i] = count++;
        }
    }
    
    for(int i=0;i<ans.size();i++) {
        if(ans[i] == -1) {
            ans[i] = count;
        }
    }
    set<int> st;

    for(auto x: ans) {
        st.insert(x);
    }
    cout<<st.size()<<endl;
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int __ = 1;
    cin >> __;
    while (__--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            temp.push_back({})
            g[u].push_back({v, i + 1});
            g[v].push_back({u, i + 1});
        }

        if (n == 3 and m == 3) {
            cout << 3 << nl << 1 << " " << 2 << " " << 3 << nl;
            continue;
        }
        vector<int> ans(m + 1);
        vector<bool> vis(m + 1);
        function<void(int, int, int)> dfs = [&] (int node, int f, int cur) {
            for (auto &v : g[node]) {
                if (!vis[v.ss]) {
                    if (f == 0) {
                        ans[v.ss] = cur + 1;
                        cur ^= 1;
                    }
                    else ans[v.ss] = 2;
                    vis[v.ss] = true;
                    dfs(v.ff, f, cur);
                }
            }
        };
        if (n == 4 and m == 4) {
            cout << 2 << nl;
            dfs(0, 0, 1);
            for (int i = 1; i <= 4; i++) {
                cout << ans[i] << " ";
            }
            cout << nl;
            continue;
        }
        cout << 2 << nl;
        int node = 0;
        for (int i = 0; i < n; i++) {
            if (sz(g[i]) < n - 1) {
                node = i;
                break;
            }
        }
        dfs(node, 1, -1);
        for (auto &v : g[node]) {
            ans[v.ss] = 1;
        }
        for (int i = 1; i <= m; i++) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
}