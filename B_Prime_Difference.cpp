/*
authot:Karan
created:17.05.2021 10:31:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

bool isPrime(ll n) {
    bool ans=true;
    for(ll i=2;i*i<=n;i++) {
        if(n%i==0) {
            ans=false;
            break;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        ll p=2*n+3;
        if(isPrime(p)) {
            cout<<p<<" "<<"2"<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}