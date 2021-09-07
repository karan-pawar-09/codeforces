/*
author:Karan
created:22.08.2021 22:56:05
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

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
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        map<ll,ll> M;
        for(ll i=0;i<n;i++) {
            M[arr[i]]++;
        }
        bool ans=true;
        int temp=0;
        for(auto x:M) {
            if(x.first!=0 && x.first!=1 && x.first!=-1) {
                temp+=x.second;
            }
        }
        if(temp>1) {
            ans=false;
        }
        temp=0;
        if(M.find(-1)!=M.end()) {
            for(auto x:M) {
                if(x.first!=0 && x.first!=1 && x.first!=-1) {
                    temp+=x.second;
                }
            }
            if(M[-1]>=2) {
                if(M.find(1)==M.end()) {
                    ans=false;
                }
            }
        }
        if(temp>=1) ans=false;
        
        if(ans) {
            cout<<1<<endl;
        }
        else {
            cout<<0<<endl;
        }
    }
}