#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    vector<ll> aray(100007);
        ll ans=1;
        aray[0]=1;
        for(ll i=1;i<100007;i++) {
            ans=((ans%MOD)*(2%MOD))%MOD;
            aray[i]=ans;
        }    
    while(t--) {
        ll n;
        cin>>n;    
        vector<ll> arr(n);
        ll sum=0;
        for(ll i=0;i<n;i++) {
            cin>>arr[i];
        }
        for(ll i=0;i<n;i++) {
            if(arr[i]%2==0) {
                sum=(sum%MOD+aray[i]%MOD)%MOD;
            }
        }
        cout<<sum%MOD<<endl;
    }
}