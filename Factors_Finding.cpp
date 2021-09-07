/*
author:Karan
created:02.09.2021 16:41:11
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n;
    cin>>n;
    vector<ll> ans;
    for(ll i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(n/i == i) {
                ans.push_back(i);
            }
            else {
                ans.push_back(n/i);
                ans.push_back(i);
            }
        }
    }
    sort(all(ans));
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
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}