/*
author:Karan
created:28.08.2021 21:53:47
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll countSetBits(ll n) {
    unsigned ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        vector<ll> sum(n+1,0);
        for(ll i=1;i<=n;i++) {
            sum[i]=sum[i-1]+arr[i-1];
        }
        ll ans=1e9+7;
        if(sum[n]%m==0) {
            cout<<0<<endl;
            continue;
        }
        for(ll suf=1;suf<=n;suf++) {
            ll temp=countSetBits(suf);
            for(ll pref=suf;;pref=(pref-1)&suf) {
                if(pref+suf>=n) {
                    if(pref==0) break;
                    continue;
                }
                ll ss=(sum[n-suf]-sum[pref]);
                if(ss%m==0) {
                    ans=min(ans,temp);
                }
                if(pref==0) break;
            }
        }
        if(ans!=1e9+7) {
            cout<<ans<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
}