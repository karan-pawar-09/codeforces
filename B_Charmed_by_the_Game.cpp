/*
author:Karan
created:24.08.2021 20:16:51
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll a,b;
    cin>>a>>b;
    set<ll> ans;
    {
        ll serves=(a+b+1)/2;
        ll def=a+b-serves;
        for(ll i=0;i<=serves;i++) {
            ll rem=a-i;    
            ll rem2=serves-i;        
            if(rem<=def and rem>=0) {
                if(rem2>=0 and rem2<=serves) {
                    rem+=rem2;
                }
                ans.insert(rem);
            }
            
        }
        for(ll i=0;i<=def;i++) {
            ll rem=b-i;
            ll rem2=def-i;            
            if(rem<=serves and rem>=0) {
                if(rem2>=0 and rem2<=def) {
                    rem+=rem2;
                }
                ans.insert(rem);
            }
        }
    }
    {
        ll def=(a+b+1)/2;
        ll serves=a+b-def;
        for(ll i=0;i<=serves;i++) {
            ll rem=a-i;
            ll rem2=serves-i;
            if(rem<=def and rem>=0) {
                
                if(rem2>=0 and rem2<=serves) {
                    rem+=rem2;
                }
                ans.insert(rem);
            }
        }
        for(ll i=0;i<=def;i++) {
            ll rem=b-i;
            ll rem2=def-i;
            
            if(rem<=serves and rem>=0) {
                if(rem2>=0 and rem<=def) {
                    rem+=rem2;
                }
                ans.insert(rem);
            }
        }
    }
    
    cout<<ans.size()<<endl;
    for(auto x:ans) {
        cout<<x<<" ";
    }
    cout<<endl;
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