/*
authot:Karan
created:18.05.2021 16:17:07
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
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
            ll fib=one+two;
            one=two;
            two=fib;
        }
        cout<<two<<endl;
    }
}