/*
author:Karan
created:07.07.2021 20:07:23
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
        ll a,b;
        cin>>a>>b;
        if(a==b) cout<<0<<" "<<0<<endl;
        else {
            ll diff=abs(a-b);
            ll k=a/diff;
            ll p=(a/diff)+1;
            ll ans=min(abs(diff*k-a),abs(diff*p-a));
            cout<<diff<<" "<<ans<<endl;
        }
    }
}