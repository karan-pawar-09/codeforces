#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll ans=1e9;
        for(ll i=1;i*i<=n;i++) {
            ans=min(ans,(i-1)+(n-1)/i);
        }
        cout<<ans<<endl;
    }
}