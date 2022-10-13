/*
    author:Karan
    created:03.08.2022 20:43:30
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
    ll n,x,y,a,b;
    cin>>n>>x>>y>>a>>b;
    if(x*b < y*a) {
        cout<<"PETROL"<<endl;
    } else if(x*b > y*a) {
        cout<<"DIESEL"<<endl;
    } else {
        cout<<"ANY"<<endl;
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