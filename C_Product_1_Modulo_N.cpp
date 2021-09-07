/*
author:Karan
created:28.05.2021 10:03:06
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

set<ll> s;
ll fact(ll a,ll mod) {
    ll ans=1;
    for(ll i=1;i<a;i++) {
        if(__gcd(mod,i)==1) {
            ans=((ans%mod)*(i%mod))%mod;
            s.insert(i);
        }            
    }
    return ans;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll factorial=fact(n,n);
    ll x,y;
    ll a=gcd(factorial,n,x,y);
    if((x%n+n)%n!=1) {
        s.erase((x%n+n)%n);
    }
    cout<<s.size()<<endl;
    for(ll x:s) {
        cout<<x<<" ";
    }
    cout<<endl;
}