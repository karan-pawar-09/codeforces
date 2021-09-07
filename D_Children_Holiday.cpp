#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
bool isGood(vector<ll>t,vector<ll>z,vector<ll>y,ll x,ll n,ll m) {
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans+=(x*z[i])/(t[i]*z[i]+y[i])+min(((x%(t[i]*z[i]+y[i]))/t[i]),z[i]);
    }
    return ans>=m;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll m,n;
    cin>>m>>n;
    vector<ll> t(n);
    vector<ll> z(n);
    vector<ll> y(n);
    for(ll i=0;i<n;i++) {
        cin>>t[i]>>z[i]>>y[i];
    }
    ll l=-1;
    ll r=(ll)1e18;
    while(r>l+1) {
        ll x=l+(r-l)/2;
        if(isGood(t,z,y,x,n,m)) {
            r=x;
        }
        else {
            l=x;
        }
    }
    vector<ll>ans;
    for(ll i=0;i<n;i++) {
        ans.push_back((r*z[i])/(t[i]*z[i]+y[i])+min(((r%(t[i]*z[i]+y[i]))/t[i]),z[i]));
    }
    cout<<r<<endl;
    for(ll i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}