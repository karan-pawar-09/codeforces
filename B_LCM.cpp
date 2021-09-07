#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll answer(ll a) {
    ll p=a;
    ll ans=1;
    for(ll i=2;i*i<=p;i++) {
        ll count=0;
        if(p%i==0){
            
            while(p%i==0){
                p/=i;
                count++;                
            }
        }
        ans*=(count+1);        
    }
    if(p>1){
        ans*=2;
    }
    return ans;
}

int main() {
    ll b;
    cin>>b;
    ll k=answer(b);
    cout<<k;
}