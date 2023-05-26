/*
    author:Karan
    created:03.03.2023 14:57:39
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
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    string p = a;
    string q = b;
    sort(all(p));
    sort(all(q));
    if(p != q) {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n;i++) {
        if(i < k && n-1-i < k) {
            if(a[i] != b[i]) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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