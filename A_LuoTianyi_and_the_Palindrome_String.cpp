/*
    author:Karan
    created:06.07.2023 12:15:44
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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int len = -1;
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j >= i; j--) {
            if(s[i] != s[j]) {
                len = max(len, j - i + 1 + min(i, n - 1 - j) * 2);
            }
        }
    }
    cout << len << endl;
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