#include <bits/stdc++.h>
using namespace std;
int cf;
int dfs(int i, vector<int> &a, vector<int> &b, vector<vector<int>> &g) {
    int r = 0;
    if (a[i] > 0) {
        if (i == 0) {
            cf--;
        }
        a[i]--;
        r = 1;
    }
    for (int j = 0; j < g[i].size(); j++) {
        a[i] += dfs(g[i][j], a, b, g);
    }
    if (a[i] > b[i]) {
        cf -= (a[i] - b[i]);
        a[i] = b[i];
    }
    return r;
}
int ans(vector<int> &a, vector<int> &b, vector<vector<int>> &c) {
    int n = a.size();
    cf = 0;
    int sk = 0;
    vector<vector<int>> g(n);
    for (int i = 0; i < c.size(); i++) {
        g[c[i][0] - 1].push_back(c[i][1] - 1);
    }
    for (int i = 0; i < a.size(); i++) {
        cf += a[i];
    }
    while (cf > 0) {
        dfs(0, a, b, g);
        sk++;
    }
    return sk;
}
int main() {
    
    int n;
    cin >> n;   
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    vector<vector<int>> c(n-1,vector<int>(2));
    for(int i=0;i<n-1;i++) {
        cin >> c[i][0];
        cin >> c[i][1];
    }

    cout<<ans(a, b, c);
}