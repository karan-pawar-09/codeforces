/*
    author:Karan
    created:14.03.2022 16:09:23
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
int val[mx];
int ans[mx];
vector<int> arr[mx];
multiset<int> s;

void dfs(int node, int par) {
    bool used = false;
    if (s.find(val[node]) != s.end()) {
        used = true;
        s.erase(s.find(val[node]));
    }
    ans[node] = *s.begin();
    for (auto x : arr[node]) {
        if (x != par) {
            dfs(x, node);
        }
    }
    if (used) {
        s.insert(val[node]);
    }
}

void solve() {
    int n, a, b;
    cin >> n;
    s.clear();
    s.insert(0);
    for (int i = 1;i <= n;i++) {
        cin >> val[i];
        s.insert(i);
        arr[i].clear();
    }
    for (int i = 0;i < n - 1;i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(1, 0);
    int mex = 0;
    for (int i = 1;i <= n;i++) {
        mex = max(mex, ans[i]);
    }
    cout << mex << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}