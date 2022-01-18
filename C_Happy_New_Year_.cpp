/*
    author:Karan
    created:08.01.2022 17:43:20
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



ll power(ll x, ll y) {
    ll res = 1; 
    x = x;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x); 
        y = y>>1;
        x = (x*x);
    }
    return res;
}

void solve() {
    ll k;
    cin>>k;
    vector<bool> ans(64,false);
    for(int i=0;i<64;i++) {
        if(k&(power(2,i))) {
            ans[i]=true;
        }
    }
    bool print=false;
    for(int i=63;i>=0;i--) {
        if(ans[i]) {
            print=true;
            cout<<2;
        } else {
            if(print)cout<<0;
        }
    }
    cout<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}