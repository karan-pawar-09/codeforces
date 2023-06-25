/*
    author:Karan
    created:24.06.2023 19:48:56
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

bool isGood(int res, int x) {
    for(int i = 0; i < 32; i++) {
        if((res & 1<<i) && !(x & 1<<i)) return false;
    }
    return true;
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int res = 0;
    for(int i = 0; i < n; i++) {
        if(isGood(res | a[i], x)) {
            res |= a[i];
        } else {
            break;
        }
    }
    for(int j = 0; j < n; j++) {
        if(isGood(res | b[j], x)) {
            res |= b[j];
        } else {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(isGood(res| c[i], x)) {
            res |= c[i];
        } else {
            break;
        }
    }
    if(res == x) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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