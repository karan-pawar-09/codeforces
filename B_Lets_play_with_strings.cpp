#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        ll a,b;
        cin>>n;
        cin>>a>>b;
        string p,q;
        cin>>p;
        cin>>q;
        ll cost;
        ll diff=0;
        for(int i=0;i<n;i++) {
            if(q[i]!=p[i]) {
                diff++;
            }
        }
        cost=diff*b;    
        for(ll i=1;i<n;i++) {
            diff=0;
            rotate(p.begin(),p.begin()+1,p.end());
            for(int i=0;i<n;i++) {
                if(q[i]!=p[i]) {
                    diff++;
                }
            }
            ll localcost=(a*i)+(b*diff);
            cost=min(cost,localcost);
        }
        cout<<cost<<endl;
    }
}