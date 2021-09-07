#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
bool isTrue(ll s,ll h,ll w,ll n) {
    return (s/h)*(s/w)>=n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll w,h,n;
    cin>>w>>h>>n;
    ll l=0;
    ll r=1;
    while((r/w)*(r/h)<n) {
        r*=2;
    }
    while(r>l+1) {
        ll m=l+(r-l)/2;
        if(isTrue(m,h,w,n)) {
            r=m;
        }
        else {
            l=m;
        }
    }
    cout<<r<<endl;
}