/*
author:Karan
created:04.07.2021 13:33:17
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
ll GCD(ll a,ll b) {
    if(a==0) return b;
    return GCD(b%a,a);
}
ll LCM(ll a,ll b) {
    return (a/GCD(a,b))*b;
}
const ll MOD=(ll)1e9+7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll lcm=1;
        ll ans=0;
        for(ll i=2;i<50;i++) {
            ans+=i*((n/lcm)-(n/LCM(lcm,i)));
            lcm=LCM(lcm,i);
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
}