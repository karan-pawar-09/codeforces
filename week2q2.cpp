/*
authot:Karan
created:18.05.2021 16:21:13
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'
const ll mod=10;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    if(n==0) {
        cout<<1<<endl;
    }
    else if(n==1) {
        cout<<1<<endl;
    }
    else {
        ll one=1;
        ll two=1;
        for(int i=2;i<n;i++) {
            ll fib=(one%mod+two%mod)%mod;
            one=two;
            two=fib;
        }
        cout<<two<<endl;
    }
}