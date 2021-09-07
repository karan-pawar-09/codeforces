/*
author:Karan
created:09.08.2021 14:07:02
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    ll sum=0;
    vector<vector<ll>> uni(n+1);
    unordered_map<ll,vector<ll>> M;
    vector<ll> a(n),b(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<n;i++) {
        cin>>b[i];
        sum+=b[i];
    }
    for(ll i=0;i<n;i++) {
        M[a[i]].push_back(b[i]);
    }
    for(auto &x:M) {
        sort(all(x.second),greater<ll>());
    }
    ll maxi=0;
    for(auto &x:M) {
        ll prev=0;
        for(auto &y:x.second) {            
            y+=prev;   
            prev=y;        
        }
        maxi=max(maxi,(ll)x.second.size());
    }
    vector<ll> ans(n+1,0);
    for(auto x:M) {
        int sz=x.second.size();
        for(int j=1;j<=sz;j++) {
            int rem=sz%j;
            ans[j]+=x.second[sz-1-rem];
        }
    }
    for(ll i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
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