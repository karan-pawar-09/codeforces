/*
author:Karan
created:30.07.2021 20:36:01
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
        ll m;
        cin>>m;
        vector<ll> a(m);
        vector<ll> b(m);
        for(ll i=0;i<m;i++) {
            cin>>a[i];
        }
        for(ll i=0;i<m;i++) {
            cin>>b[i];
        }
        vector<ll> c(m);
        vector<ll> saf(m),sal(m),sbf(m),sbl(m);
        saf[0]=a[0];
        sbf[0]=b[0];
        for(ll i=1;i<m;i++) {
            saf[i]=a[i]+saf[i-1];
            sbf[i]=b[i]+sbf[i-1];
        }
        sal[m-1]=a[m-1];
        sbl[m-1]=b[m-1];
        for(ll i=m-2;i>=0;i--) {
            sal[i]=a[i]+sal[i+1];
            sbl[i]=b[i]+sbl[i+1];
        }
        for(ll i=0;i<m;i++) {
            ll ans=0;
            ll check1=i-1;
            ll check2=i+1;
            if(check1>=0) {
                ans=max(ans,sbf[check1]);
            }
            if(check2<m) {
                ans=max(ans,sal[check2]);
            }
            c[i]=ans;
        }
        
        cout<<*min_element(all(c))<<endl;
    }
}