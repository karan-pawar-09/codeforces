/*
author:Karan
created:09.08.2021 13:10:19
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    string s;
    cin>>s;
    ll n=s.size();
    ll par[2]={-1,-1};
    ll ans=0;
    for(ll i=0;i<n;i++) {
        if(s[i]!='?') {
            ll k=s[i]-'0';
            par[k^(i%2)]=i;
        }
        ans+=(i-min(par[0],par[1]));
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