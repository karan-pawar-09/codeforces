/*
author:Karan
created:14.08.2021 22:41:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll l=n-1,r=0;
    for(ll i=0;i<n;i++) {
        if(s[i]=='*') {
            l=i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--) {
        if(s[i]=='*') {
            r=i;
            break;
        }
    }
    vector<ll> starf(n,0),starb(n,0);
    if(s[0]=='*') {
        starf[0]=1;
    }
    if(s[n-1]=='*') {
        starb[n-1]=1;
    }
    for(ll i=1;i<n;i++) {
        if(s[i]=='*') starf[i]=starf[i-1]+1;
        else starf[i]=starf[i-1];
    }
    for(ll i=n-2;i>=0;i--) {
        if(s[i]=='*') starb[i]=starb[i+1]+1;
        else starb[i]=starb[i+1];
    }
    ll ans=0;
    for(ll i=l;i<=r;i++) {
        if(s[i]=='.') {
            ans+=min(starf[i],starb[i]);
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
}