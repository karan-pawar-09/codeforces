/*
    author:Karan
    created:24.06.2023 17:41:04
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

char use(char a, char b) {
    if(a == '#' || b == '#') return '#';
    else return '.';
}
bool plot(vector<string> &ans, vector<string> &a, int starti, int startj) {
    int n = ans.size();
    int m = ans[0].size();
    int p = a.size();
    int q = a[0].size();
    if(((starti + p) > n) || ((startj + q) > m)) return false;
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < q; j++) {
            ans[starti + i][startj + j] = use(ans[starti + i][startj + j], a[i][j]); 
        }
    }
    return true;
}
bool helper(vector<string> & ans, vector<string> &ref, int starti, int startj) {
    int n = ans.size();
    int m = ans[0].size();
    int p = ref.size();
    int q = ref[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i < starti || j < startj || i >= p+starti || j >= q + startj) {
                if(ans[i][j] == '#') return false;
            } else {
                if(ans[i][j] != ref[i - starti][j - startj]) return false;
            }
        }
    }
    return true;
}
bool check(vector<string> &ans, vector<string> &ref) {
    int n = ans.size();
    int m = ans[0].size();
    int p = ref.size();
    int q = ref[0].size();
  
    for(int i = 0; i <= (n - p); i++) {
        for(int j = 0; j <= (m - q); j++) {
            if(helper(ans, ref, i, j)) return true;
        }
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p, q;
    cin >> p >> q;
    vector<string> b(p);
    for(int i = 0; i < p; i++) {
        cin >> b[i];
    }
    int r, s;
    cin >> r >> s;
    vector<string> c(r);
    for(int i = 0; i < r; i++) {
        cin >> c[i];
    }
    vector<string> ans(max({r, n, p}));
    for(auto &x: ans) {
        for(int i = 0; i < max({s, q, m}); i++) {
            x.push_back('.');
        }
    }
    for(int i = 0; i < max({r, n, p}); i ++) {
        for(int j = 0; j < max({s, q, m}); j++) {
            for(int k = 0; k < max({r, n, p}); k++) {
                for(int p = 0; p < max({s, q, m}); p++) {
                    if(plot(ans, a, i, j)) {
                        if(plot(ans, b, k, p)) {
                            cout<<i<<" "<<j<<" "<<k<<" "<<p<<endl;
                            for(auto x: ans) {
                                cout<<x<<endl;
                            }
                            cout<<endl;
                            if(check(ans, c)) {
                                cout<<"Yes"<<endl;
                                return;
                            }
                        }
                    }
                    for(auto &x: ans) {
                        for(auto &y: x) y == '.';
                    }
                }
            }
        }
    }
    cout<<"No"<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
}