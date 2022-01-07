/*
authot:Karan
created:18.05.2021 16:31:57
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

ll pisano(ll m) {
    ll prev = 0;
    ll curr = 1;
    ll res = 0; 
    for(int i = 0; i < m * m; i++) {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp; 
        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,mod;
    cin>>n>>mod;
    ll t=pisano(mod);
    n%=t;
    if(n==0) {
        cout<<0<<endl;
    }
    else if(n==1) {
        cout<<1<<endl;
    }
    else {
        ll one=0;
        ll two=1;
        for(int i=2;i<=n;i++) {
            ll fib=(one%mod+two%mod)%mod;
            one=two;
            two=fib;
        }
        cout<<two<<endl;
    }
}