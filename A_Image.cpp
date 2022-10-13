/*
    author:Karan
    created:27.08.2022 20:07:33
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
    char a,b,c,d;
    set<char> s;
    cin>>a>>b>>c>>d;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    if(s.size()==1) {
        cout<<0<<endl;
    } else if(s.size() == 2) {
        cout<<1<<endl;
    } else if(s.size() == 3) {
        cout<<2<<endl;
    } else {
        cout<<3<<endl;
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