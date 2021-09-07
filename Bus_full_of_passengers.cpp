/*
author:Karan
created:17.08.2021 20:16:34
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

void solve() {
    ll n,m,q;
    cin>>n>>m>>q;
    vector<ll> arr(n+1,0);
    bool ans=true;
    ll mm=0;
    while(q--) {
        char c;
        ll k;
        cin>>c>>k;
        if(c=='-') {
            if(arr[k]>0) {
                arr[k]--;
                mm--;
            }
            else {
                ans=false;
            }
        }
        else {
            if(arr[k]==0) {
                arr[k]++;
                mm++;
            }
            else {
                ans=false;
               
            }
            if(mm>m) {
                ans=false;
            }
        }
    }
    ans?cout<<"Consistent"<<endl:cout<<"Inconsistent"<<endl;
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