/*
author:Karan
created:08.07.2021 12:12:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)10;

ll power(long long x, ll y, ll mod) {
    ll res = 1; 
    x = x % mod;   
    if (x == 0) return 0;  
    while (y > 0) {        
        if (y & 1)
            res = (res*x) % mod; 
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll sum=0;
    for(ll i=0;i<=1989;i++) {
        sum=(sum%mod+power(9,i,mod)%mod)%mod;
    }
    cout<<sum<<endl;
}