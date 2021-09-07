/*
author:Karan
created:29.05.2021 23:17:24
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    int ans=0;
    int k=0;
    for(int i=0;i<m;i++) {
        while(a[k]<=b[i]) {
            k++;
            if(a[k]==b[i]) {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}