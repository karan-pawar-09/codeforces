#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll factorial(ll a) {
    ll ans=1;
    for(ll i=2;i<=a;i++) {
        ans=(ans%MOD*i%MOD)%MOD;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x,n,pos;
    cin>>n>>x>>pos;
    ll answer=1;
    ll greater=n-x;
    ll smaller=x-1;
    ll l=0;
    ll r=n;
    ll space=n-1;
    while(l<r) {
        ll mid=(l+r)/2;
        if(mid==pos) {
            l=mid+1;
        }
        else if(mid>pos) {
            answer=((answer%MOD) * (greater%MOD))%MOD;
            greater--;
            space--;
            r=mid;
        }
        else{
            answer=((answer%MOD) * (smaller%MOD))%MOD;
            smaller--;
            space--;
            l=mid+1;
        }
    }
    if(l>0&&(l-1)==pos) {
        answer=((answer%MOD)*(factorial(space))%MOD)%MOD;
    }
    else {
        answer=0;
    }
    cout<<answer<<endl;
}