/*
author:Karan
created:01.08.2021 20:33:33
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
    ll n,m;
    cin>>n>>m;
    vector<ll> smaller(n+7,0);
    vector<ll> bigger(n+7,0);
    while(m--) {
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        bigger[a]++;
        smaller[b]++;
    }
    ll ans=0;
    for(ll i=1;i<=n;i++) {
        if(bigger[i]==0) {
            ans++;
        }
    }
    ll q;
    cin>>q;
    while(q--) {
        ll p,s,t;
        cin>>p;
        if(p==1) {
            cin>>s>>t;
            if(s>t) swap(s,t);
            if(bigger[s]==0) {
                ans--;
            }
            bigger[s]++;
            smaller[t]++;
        }
        else if(p==2) {
            cin>>s>>t;
            if(s>t) swap(s,t);
            bigger[s]--;
            smaller[t]--;
            if(bigger[s]==0) {
                ans++;
            }
        }
        else {
            cout<<ans<<endl;
        }
    }
}