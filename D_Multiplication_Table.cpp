/*
author:Karan
created:23.06.2021 14:42:47
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll n,m;
ll isGood(ll no) {
    ll res=0;
    for(ll i=1;i<=n;i++) res+=min(m,(no-1)/i);
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll k;
    cin>>n>>m>>k;
    ll l=0;
    ll r=(ll)1e18+7;
    while(l+1<r) {
        ll gg=l+(r-l)/2;
        if(isGood(gg)<k) {
            l=gg;
        }
        else {
            r=gg;
        }
    }
    cout<<l<<endl;
}
