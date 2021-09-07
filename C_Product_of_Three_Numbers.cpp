#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans(ll a) {
    ll k=0;
    for(ll i=2;i*i<a;i++) {
        ll count=0;
        if(a%i==0){
            k++;
            a/=i;
        }
    }
    if(a>1) {
        k++;
    }
    return k;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        if(ans(n)>2){
            cout<<"YES"<<endl;
            for(ll i=2,count=0;i<n,count<2;i++) {
                if(n%i==0) {
                    cout<<i<<" ";
                    n/=i;
                    count++;
                }
            }
            cout<<n<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}