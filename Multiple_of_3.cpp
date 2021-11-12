/*
    author:Karan
    created:09.11.2021 17:18:59
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
    ll k,a,b;
    cin>>k>>a>>b;
    ll p=a+b;
    ll sum=0;
    sum=p;
    if(p%2) {
        ll z=p;
        z%=10;        
        k-=3;
        if(k>0) {
            sum+=z;
            ll x=k/4;
            ll v=k%4;  
            z*=2;
            z%=10;      
            for(ll i=0;i<v;i++) {
                sum+=z;
                z*=2;
                z%=10;
            }
            sum+=20*x;
        }
        (sum%3==0)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
    else {
        k-=2;
        if(k>0) {
            ll x=k/4;
            ll v=k%4;
            ll z=p%10;       
            for(ll i=0;i<v;i++) {
                sum+=z;
                z*=2;
                z%=10;
            }
            sum+=20*x;
        }
        cout<<sum<<endl;
        (sum%3==0)?cout<<"YES"<<endl:cout<<"NO"<<endl;
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