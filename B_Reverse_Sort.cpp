/*
    author:Karan
    created:12.11.2021 20:27:13
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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    ll one=0;
    for(ll i=0;i<n;i++) {
        if(s[i]=='1') {
            one++;
        }
    }
    ll zero=n-one;
    for(ll i=0;i<zero;i++) {
        if(s[i]=='1') {
            ans++;
        }
    }
    if(ans==0) {
        cout<<0<<endl;
    }
    else {
        cout<<1<<endl;
        cout<<ans*2<<" ";
        for(ll i=0;i<zero;i++) {
            if(s[i]=='1') {
                cout<<i+1<<" ";
            }
        }
        for(ll i=zero;i<n;i++) {
            if(s[i]=='0') {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
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