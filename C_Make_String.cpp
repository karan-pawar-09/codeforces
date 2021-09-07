#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll power(ll x, ll y, ll p) { 
    ll res = 1; 
    x = x % p;   
    if (x == 0) return 0;  
    while (y > 0) { 
        if (y & 1) 
            res = (res*x) % p; 
         y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll mod=(ll)1e9+7;
    vector<ll> address(q);
    vector<char> letter(q);
    map<ll,set<char>> ans;
    for(ll i=0;i<q;i++) {
        cin>>address[i];
    }
    for(ll i=0;i<q;i++) {
        cin>>letter[i];
    }
    for(ll i=0;i<q;i++) {
        ans[address[i]].insert(letter[i]);
    }
    ll no=1;
    for(auto i:ans) {
        no=((26-(i.second).size())%mod*no%mod)%mod;
    }
    n=n-ans.size();
    no=(power(26,n,mod)%mod*no%mod)%mod;
    cout<<no<<endl;
}