/*
    author:Karan
    created:18.06.2023 14:50:15
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
    string s, t;
    cin >> s >> t;
    if(s == t) {
        cout<<0<<endl; 
        return;
    }
    reverse(all(t));
    if(s == t) {
        cout<<2<<endl;
        return;
    }
    reverse(all(t));
    int fr = 0;
    int bk = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != t[i]) fr++;
    }
    for(int i= 0; i < n;i++) {
        if(s[i] != t[n-1-i]) bk++;
    }
    
    if(fr % 2) {
        fr = fr * 2 - 1;
    } else {
        fr += fr;
    }

    if(bk % 2 == 0) {
        bk = 2 * bk - 1;
    } else {
        bk += bk;
    }
    cout<<min(bk, fr)<<endl;
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