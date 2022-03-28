/*
    author:Karan
    created:14.03.2022 22:19:12
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
    int v, a, b, c;
    cin >> v >> a >> b >> c;
    v %= (a + b + c);
    if (v < a) {
        cout << "F" << endl;
    }
    else if (v < (a + b)) {
        cout << "M" << endl;
    }
    else {
        cout << "T" << endl;
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