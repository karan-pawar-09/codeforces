/*
authot:Karan
created:14.05.2021 20:03:59
*/
#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll mod = (ll) 1e9+7;
ll power(ll x, unsigned ll y) {
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return (power(x, y/2)%mod*power(x, y/2)%mod)%mod;
    else
        return (x%mod*power(x, y/2)%mod*power(x, y/2)%mod)%mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;        
        cout<<power(2,n-1)<<endl;
    }
}