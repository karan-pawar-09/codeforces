/*
author:Karan
created:03.08.2021 11:19:08
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll lowerbound(vector<ll> &a,ll val) {
    ll l=0;
    ll r=a.size();
    while(l+1<r) {
        ll m=(l+r)/2;
        if(a[m]<=val) {
            l=m;
        }
        else {
            r=m;
        }
    }
    return a[l];
}
ll upperbound(vector<ll> &a,ll val) {
    ll l=-1;
    ll r=a.size()-1;
    while(l+1<r) {
        ll m=(l+r)/2;
        if(a[m]>=val) {
            r=m;
        }
        else {
            l=m;
        }
    }
    return a[r];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    for(ll i=0;i<m;i++) {
        cin>>b[i];
    }
    a.push_back((ll)1e16+7);
    sort(all(a));
    sort(all(b));
    ll ans=1e18+7;
    for(ll i=0;i<m;i++) {
        ll temp=abs(b[i]-upperbound(a,b[i]));
        ll temp1=abs(b[i]-lowerbound(a,b[i]));
        ans=min({ans,temp,temp1});
    }
    cout<<ans<<endl;
}