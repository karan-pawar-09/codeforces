#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isGood(ll n,ll a,ll b,ll x) {
    string s=to_string(n);
    ll k=s.size();
    if(((a*n)+(b*k))<=x) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,x;
    cin>>a>>b>>x;
    ll l=0;
    ll r=(ll)1e10;
    while(r>1+l) {
        ll m=l+(r-l)/2;
        if(isGood(m,a,b,x)) {
            l=m;
        }
        else {
           r=m;
        }
    }
    cout<<min(l,(ll)(1e9))<<endl;
}