#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double x,y,r;
    cin>>x>>y>>r;    
    r+=1e-14;
    ll ans=0;
    for(ll i=ceil(x-r);i<=floor(x+r);i++) {
        long double horizontalDistFromaxis=sqrt(r*r-(x-i)*(x-i));
        ll a=floor(y+horizontalDistFromaxis);
        ll b=ceil(y-horizontalDistFromaxis);
        ans+=a-b+1;
    }
    cout<<ans<<endl;
}
