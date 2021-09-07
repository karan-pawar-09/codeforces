/*
author:Karan
created:09.07.2021 10:52:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll xork(ll a, ll b, ll k) {
    vector<ll> one(40,0);
    vector<ll> two(40,0);
    ll i=0;
    while(a>0) {
        one[i]=a%k;
        a=a/k;
        i++;
    }
    i=0;
    while(b>0) {
        two[i]=b%k;
        b=b/k;
        i++;
    }
    vector<ll> ans(40);
    for(ll j=0;j<40;j++) {
        ans[j]=(one[j]+two[j])%k;
    }
    ll final=0;
    ll pow=1;
    ll first=0;
    ll second=0;

    for(ll j=0;j<40;j++) {
        final+=(ans[j]*pow);
        first+=(one[j]*pow);
        second+=two[j]*pow;
        if(pow*k<=1e18+7) 
            pow*=k;
    }
    return final;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll ans=0;
        ll n,k,pp;
        cin>>n>>k;
        for(ll i=0;i<n;i++) {
            if(i!=0)
            ans=xork(i,i-1,k);
            if(i==0) ans=0;
            cout<<ans<<endl;
            cout.flush();
            cin>>pp;
            if(pp==1) {
                break;
            }
        }  
    }
}