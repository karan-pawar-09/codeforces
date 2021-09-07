#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> p(n);
    ll odd1=0;
    ll even1=0;
    for(ll i=0;i<n;i++) {
        cin>>p[i];
        if(p[i]%2) {
            odd1++;
        }
        else {
            even1++;
        }
    }
    ll m;
    cin>>m;
    vector<ll> q(m);
    ll odd2=0;
    ll even2=0;
    for(ll i=0;i<m;i++) {
        cin>>q[i];
        if(q[i]%2) {
            odd2++;
        }
        else {
            even2++;
        }
    }
    
    cout<<odd1*odd2+even1*even2<<endl;
}