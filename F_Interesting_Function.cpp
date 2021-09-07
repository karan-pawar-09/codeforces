/*
author:Karan
created:10.06.2021 20:58:16
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll l,r;
        cin>>l>>r;
        ll k=10;
        ll ans=r-l;
        for(ll i=1;i<10;i++) {
            ans+=(r/k)-(l/k);
            k*=10;
        }
        cout<<ans<<endl;
    }
}