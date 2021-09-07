#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll t,ll x, ll y,ll n) {
    t-=min(x,y);
    if(t<0) {
        return 0;
    }
    return (t/x)+(t/y)+1>=n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,y;
    cin>>n>>x>>y;
    ll l=0;
    ll r=(ll)1e18;
    while(r>l+1) {
        ll m=l+(r-l)/2;
        if(isGood(m,x,y,n)) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout<<r<<endl;
}