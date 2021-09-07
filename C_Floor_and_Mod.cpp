#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll x,y;
        cin>>x>>y;
        ll ans=0;
        for(ll i=1;i*i<=x;i++) {
            ans+=max(0LL,min(y,(x-i)/i)-i);
        }
        cout<<ans<<endl;
    }
}