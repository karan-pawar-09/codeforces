/*
    author:Karan
    created:17.02.2023 13:58:13
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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int count1 = 0;
    int count2 = 0;
    for(int i=1;i<n;i++) {
        if(a[i]==a[i-1]) {
            count1++;
        }
    }
    for(int i=1;i<m;i++) {
        if(b[i] == b[i-1]) {
            count2++;
        }
    }
    if(count1 > 1 || count2 > 1 || (count1&&count2)) {
        cout << "NO" << endl;
    } else {
        if(a.back() != b.back() || (!count1 && !count2)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
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