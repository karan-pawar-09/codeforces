/*
    author:Karan
    created:05.02.2022 18:04:51
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
    ll a,s;
    cin>>a>>s;
    ll x=s-a;
    ll p,q;
    p=a;
    q=s-p;
    // assert();
    if(x>=0 and (p&q) ==a and (p+q)==s) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}