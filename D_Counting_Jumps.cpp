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
        ll n,k,m;
        cin>>n>>k>>m;
        vector<ll> ans(m,0);
        ll a=0;
        for(ll i=k;i<=k*m;i+=k) {
            ans[i%m]+=n/m;
        }
        for(ll i=(n/m)*m*k;i<=n*k;i+=k) {
            ans[i%m]++;
        }
        for(ll i=0;i<m;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}