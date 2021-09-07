#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPrime(ll n) { 
      if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false; 
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;   
    return true; 
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y;
    cin>>x>>y;
    ll k=x;
    ll p=y;
    ll big=x;
    ll small=y;
    if(x<y) {
        ll temp=x;
        x=y;
        y=temp;
    }
    bool isthere=false;
    for(ll i=x;i>=y;i--) {
        if(isPrime(i)) {
            big=i;
            isthere=true;
            break;
        }
    }
    for(ll i=y;i>=2;i--) {
        if(isPrime(i)) {
            small=i;
            break;
        }
    }
    if(isthere) {
        k>p?cout<<big-small<<endl:cout<<small-big<<endl;
    }
    else {
        cout<<"0"<<endl;
    }
}