/*
author:Karan
created:29.05.2021 23:11:34
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<m;i++) {
        cin>>b[i];
    }
    vector<ll> c(n+m);
    ll i=0,j=0,k=0;
    while(i<n||j<m) {
        if(j==m||i<n&&a[i]<b[j]) {
            c[k++]=a[i++];
        }
        else {
            c[k++]=b[j++];
        }
    }
    for(ll k:c) {
        cout<<k<<" ";
    }
    cout<<endl;
}