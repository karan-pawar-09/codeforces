#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<ll> sum(n+1,0);    
    for(ll i=1;i<=n;i++) {
        sum[i]=a[i-1]+sum[i-1];
    }
    ll damage=0;
    for(ll i=0;i<q;i++) {
        ll inp;
        cin>>inp;
        ll l=0;
        ll r=n+1;
        while(r>l+1) {
            ll m=l+(r-l)/2;
            if((sum[m]-damage)<=inp) {
                l=m;

            }
            else {
                r=m;
            }
        }
        damage+=inp;
        if(l==n) {
            l=0;
            damage=0;
            
        }        
        cout<<(n-l)<<endl;
    }
}