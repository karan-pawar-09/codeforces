/*
author:Karan
created:18.08.2021 21:29:30
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=(ll)1e18;
ll lcs(string &X, string &Y){   
    ll ans=0;
    ll j=0;
    for(ll i=0;i<X.size();i++) {
        if(X[i]==Y[j]) {
            j++;
            ans++;
        }
    }
    return ans;
}
ll count(string &s, vector<string> & powers) {
    ll mini=s.size()+1;
    for(ll i=0;i<powers.size();i++) {        
        ll k=(powers[i].size()+s.size())-(2*(lcs(s,powers[i])));
        mini=min(mini,k);
    }
    return mini;
}
ll power(long long x, unsigned ll y, ll mod) {
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
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        vector<string> powers;
        for(ll i=0;i<64;i++) {
            powers.push_back(to_string(power(2,i,mod)));
        }
        string s=to_string(n);
        cout<<count(s,powers)<<endl;

    }
}