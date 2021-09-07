#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll mod=(ll)1e9+7;
    ll n;
    cin>>n;
    vector<ll> ans(n+1,0);
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=n;i++) {
        if(i-1>=0) {
            ans[i]+=ans[i-1];
            ans[i]%=mod;
        }
        if(i-2>=0) {
            ans[i]+=ans[i-2];
            ans[i]%=mod;
        }
        if(i-3>=0) {
            ans[i]+=ans[i-3];
            ans[i]%=mod;
        }
        if(i-4>=0) {
            ans[i]+=ans[i-4];
            ans[i]%=mod;
        }
        if(i-5>=0) {
            ans[i]+=ans[i-5];
            ans[i]%=mod;
        }
        if(i-6>=0) {
            ans[i]+=ans[i-6];
            ans[i]%=mod;
        }
    }
    ans[n]%=mod;
    cout<<ans[n]<<endl;
}   