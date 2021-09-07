/*
author:Karan
created:29.05.2021 23:22:48
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
    ll ans=0;
    ll k=0;
    ll temp=0;
    for(ll i=0;i<m;i++) {  
        if(i>0&&b[i]!=b[i-1]) {
            temp=0;
        }      
        while(k<n&&a[k]<=b[i]) {
            if(a[k]==b[i]) {
                temp++;
            }
            k++;
        }
        ans+=temp;
    }
    cout<<ans<<endl;
}