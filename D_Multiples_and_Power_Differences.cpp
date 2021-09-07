#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll k= 1*2/__gcd(1,2);
    for(ll i=3;i<=16;i++) {
        k=k*i/__gcd(k,i);
    }
    for(ll i=0;i<n;i++) {
        for(ll j=0;j<m;j++) {
            ll a;
            cin>>a;
            if((i+j)%2==0) {
                cout<<k<<" ";
            }
            else {
                cout<<k+a*a*a*a<<" ";
            }
        }
        cout<<endl;
    }
}