#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll calc(ll x,ll n,ll k) {
    ll sum=0;
    for(ll i=0;i<n;i++) {
        ll t=(x-1)/(i+1);
        sum+=min(t,n);
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;

    ll l=0;
    ll r=(ll)1e18;
    while(r>l+1) {
        ll m=l+(r-l)/2;
        if(calc(m,n,k)<k) {
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<l<<endl;    
}