/*
    author:Karan
    created:12.03.2022 10:56:35
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

pair<int, int> fun(string& str) {
    vector<int> v;
    stringstream ss(str);
    for (int i; ss >> i;) {
        v.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return { v[0],v[1] };
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n, vector<int>(m, 0));
    for (int i = 0;i < n;i++) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        pair<int, int> p = fun(s);
        arr[p.first][p.second] = k;
    }
    string s;
    while (true) {
        char c;
        cin >> c;
        if (c == 'Q') break;
        s.push_back(c);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
}

0 0 0 0 9
0 0 0 7 6
3 0 0 0 0
* 0 0 0 0
0 0 0 2 0