#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        bool k=false;
        vector<ll> ans(2*n,0);
        for(ll i=0;i<n;i++) {
            ll aa,ab,ac,ad;
            cin>>aa>>ab;
            cin>>ac>>ad;
            if(ab==ac)
            k=true;
        }
        if(k&&(m*m)%4==0) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}