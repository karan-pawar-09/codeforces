#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll l,r,m;
        cin>>l>>r>>m;
        ll a;
        ll b,c;
        for(int i=l;i<=r;i++) {
            ll m1=m%i;
            ll m2=i-(m%i);
            if(i<=m&&m1<=r-l) {
                a=i;
                b=r;
                c=r-m1;
                break;
            }
            else if(m2<=r-l) {
                a=i;
                b=r-m2;
                c=r;
                break;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }    
}