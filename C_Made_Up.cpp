/*
author:Karan
created:24.05.2021 09:25:52
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n),b(n),c(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
        a[i]--;
    }
    for(ll j=0;j<n;j++) {
        cin>>b[j];
        b[j]--;
    }
    for(ll i=0;i<n;i++) {
        cin>>c[i];
        c[i]--;
    }
    vector<ll> ans(n);
    for(ll i=0;i<n;i++) {
        ans[b[c[i]]]++;
    }
    ll total=0;
    for(ll i=0;i<n;i++) {
        total+=ans[a[i]];
    }
    cout<<total<<endl;
}