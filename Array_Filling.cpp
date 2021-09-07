/*
author:Karan
created:13.08.2021 20:20:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll __lcm(ll a,ll b) {
    return (a/__gcd(a,b))*b;
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
        vector<pair<ll,ll>> arr(m);
        for(ll i=0;i<m;i++) {
            cin>>arr[i].first>>arr[i].second;
        }
        sort(all(arr),greater<pair<ll,ll>>());
        ll lcm=1;
        ll rem=n;
        ll ans=0;
        for(ll i=0;i<m&&rem>0;i++) {
            lcm=__lcm(lcm,arr[i].second);
            ans+=(rem-(n/lcm))*arr[i].first;
            rem=n/lcm;
        }
        cout<<ans<<endl;
    }
}
