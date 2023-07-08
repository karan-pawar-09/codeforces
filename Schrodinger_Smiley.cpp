/*
    author:Karan
    created:05.07.2023 20:02:21
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string temp;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            temp.push_back(s[i]);
        } else {
            if(s[i] != s[i-1]) {
                temp.push_back(s[i]);
            }
        }
    }
    for(int i = 1; i < temp.size() - 1; i++) {
        if(temp[i] == ')' && temp[i-1] == ':' && temp[i+1] == ':') {
            count++;
        }
    }
    cout << count << endl;
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