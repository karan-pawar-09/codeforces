/*
    author:Karan
    created:02.02.2022 20:18:50
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
    int x;
    cin>>x;
    int a=0;
    int b=x;
    int k=x;
    int p=(1<<29);
    p--;
    int xxx=(a|b)&(b|p)&(p|a);
    assert(p<(1e9));
    assert(xxx=x);
    assert(p>x);
    cout<<a<<" "<<b<<" "<<p<<endl;
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