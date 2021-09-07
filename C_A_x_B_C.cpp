#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll answer(ll a) {
    ll p=a;
    ll ans=1;
    ll kk=0;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll ans=0;
    for(int i=2;i<n;i++) {
        ans+=(answer(i));
    }
    ans++;
    cout<<ans;
}