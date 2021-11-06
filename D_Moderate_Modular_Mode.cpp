/*
    author:Karan
    created:31.10.2021 12:31:15
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
    ll a,b;
    cin>>a>>b;
    if(a==b) {
        cout<<a<<endl;
    }
    else if(a>b) {
        cout<<(a+b)<<endl;
    }
    else {
        ll diff=abs(b-a)/2;        
        if(diff<a) {
            cout<<a+diff<<endl;
        }
        else {
            ll temp=diff;
            ll l=(b-temp)/a;
            cout<<a*l+temp<<endl;
        }
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

