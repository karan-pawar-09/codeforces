/*
author:Karan
created:31.05.2021 21:04:54
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(ar) ar.begin(),ar.end()
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll n=1e7+5;
    vector<bool> is_prime(n+1, true);
    vector<ll> primes(n+1,0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    ll k=0;
    for(ll i=2;i<n;i++) {
        if(is_prime[i]) {
            k++;
        }
        primes[i]=k;
    }
    while(t--) {
        ll n;
        cin>>n;
        if(n==2) {
            cout<<"1"<<endl;
        }
        else if(n==3) {
            cout<<"2"<<endl;
        }
        else{
            cout<<primes[n]-primes[(n/2)]+1<<endl;
        }        
    }
}