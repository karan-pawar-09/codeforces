/*
    author:Karan
    created:12.11.2021 20:06:23
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
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>c) {
        swap(a,c);
    }
    ll sum=a+c;
    ll k=2*b;
    ll diff=abs(k-sum);
    (diff%3==0)?cout<<0<<endl:cout<<1<<endl;;
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