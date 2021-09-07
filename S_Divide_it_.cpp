#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; 
    cin>>q;
    while(q--) {
        ll n;
        cin>>n;
        ll ans=0;
        while(n>1&&((n%2==0)||(n%3==0)||(n%5==0))) {
            if(n%2==0) {
                n/=2;
            }
            else if(n%3==0) {
                n=(n/3)*2;
            }
            else {
                n=(n/5)*4;
            }
            ans++;
        }
        if(n==1) {
            cout<<ans<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}