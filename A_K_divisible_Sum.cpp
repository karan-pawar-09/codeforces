#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
 bool isGood(ll x,ll n, ll k) {
     ll p=n*x;
     ll q=p/k;
     if(q*k>=n&&k*q<=p) {
         return true;
     }
     else {
         return false;
     }
 }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        
        ll l=0;
        ll r=(ll)1e10;
        while(l+1<r) {
            ll m= l+(r-l)/2;
            if(isGood(m,n,k)) {
                r=m;
            }
            else {
                l=m;
            }
        }
        cout<<r<<endl;
    }
}