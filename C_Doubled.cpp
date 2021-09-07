#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isTrue(ll a,ll n) {
    if(stoll(to_string(a)+to_string(a))<=n) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll l=0;
    ll r=(ll)1e6;
    while(l+1<r) {
        ll m=l+(r-l)/2;
        if(isTrue(m,n)) {
            l=m;
        }
        else {
            r=m;
        }
    }
    cout<<l<<endl;
}