/*
authot:Karan
created:19.05.2021 14:37:56
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

const ll mod=10;

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
    ll n;

    cin>>n;
    ll t=pisano(mod);
    ll period=n/t;
    n%=t;
    ll sum=0;
    if(n==0) {
        sum+=0;
    }
    else if(n==1) {
        sum+=1;
    }
    else {
        ll one=0;
        ll two=1;
        sum+=1;
        for(int i=2;i<=n;i++) {
            ll fib=(one%mod+two%mod)%mod;
            one=two;
            two=fib;
            sum+=fib*fib;
        }
    }
    ll one=0;
    ll two=1;
    ll ressum=1;
    for(int i=2;i<=t;i++) {
        ll fib=(one%mod+two%mod)%mod;
        one=two;
        two=fib;
        ressum+=fib*fib;
    }
    cout<<(sum+period*ressum)%mod;
}